//the draws are 1)line, elipse, rectangle, circle, polygon.
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <stdio.h>
using namespace cv;
using namespace std;

static void help();
static Scalar randomColor(RNG& rng);

int main(int argc, char** argv)
{          
        /************************************************************
        CommandLineParser::CommandLineParser(int argc, const char* const argv[], const String& keys)
        {
        impl = new Impl;
        impl->refcount = 1;

        // path to application
        size_t pos_s = String(argv[0]).find_last_of("/\\");
        if (pos_s == String::npos)
        {
            impl->path_to_app = "";
            impl->app_name = String(argv[0]);
        }
        else
        {
            impl->path_to_app = String(argv[0]).substr(0, pos_s);
            impl->app_name = String(argv[0]).substr(pos_s + 1, String(argv[0]).length() - pos_s);
        }

        impl->error = false;
        impl->error_message = "";
        
        // parse keys
        std::vector<String> k = impl->split_range_string(keys, '{', '}');
    
        int jj = 0;
        for (size_t i = 0; i < k.size(); i++)
        {
            std::vector<String> l = impl->split_string(k[i], '|', true);
            CommandLineParserParams p;
            p.keys = impl->split_string(l[0]);
            p.def_value = l[1];
            p.help_message = cat_string(l[2]);
            p.number = -1;
            if (p.keys.size() <= 0)
            {
                impl->error = true;
                impl->error_message = "Field KEYS could not be empty\n";
            }
            else
            {
                if (p.keys[0][0] == '@')
                {
                    p.number = jj;
                    jj++;
                }

                impl->data.push_back(p);
            }
        }
         // parse argv
        jj = 0;
        for (int i = 1; i < argc; i++)
        {
            String s(argv[i]);
            bool hasSingleDash = s.length() > 1 && s[0] == '-';

            if (hasSingleDash)
            {
                bool hasDoubleDash = s.length() > 2 && s[1] == '-';
                String key = s.substr(hasDoubleDash ? 2 : 1);
                String value = "true";
                size_t equalsPos = key.find('=');

                if(equalsPos != String::npos) {
                    value = key.substr(equalsPos + 1);
                    key = key.substr(0, equalsPos);
                }
                impl->apply_params(key, value);
            }
            else
            {
                impl->apply_params(jj, s);
                jj++;
            }
        }

        impl->sort_params();
        }
        ******************************************************/    
        CommandLineParser parser(argc, argv, "{help h||}");
        
        /*************************************************
        bool CommandLineParser::has(const String& name) const
        {
            for (size_t i = 0; i < impl->data.size(); i++)
            {
            for (size_t j = 0; j < impl->data[i].keys.size(); j++)
                {
                    if (name == impl->data[i].keys[j])
                    {
                        const String v = cat_string(impl->data[i].def_value);
                        return !v.empty() && v != noneValue;
                    }
                }
            }

            CV_Error_(Error::StsBadArg, ("undeclared key '%s' requested", name.c_str()));
            return false;   
        }

        ******************************************************/    
        if(parser.has("help"))
        {
                help();
                return 0; 
        }
        char wndname[] = "Drawing Demo";
        const int NUMBER = 160;
        const int DELAY = 30;
        int lineType = LINE_AA;
        int i, width = 1000, height = 700;
        int x1 = -width/2, x2 = width*3/2, y1 = -height/2, y2 = height*3/2;
        /************************************************
        class CV_EXPORTS RNG
        {
        public:
        enum { UNIFORM = 0,
               NORMAL  = 1
             };

        @brief constructor

        These are the RNG constructors. The first form sets the state to some
        pre-defined value, equal to 2\*\*32-1 in the current implementation. The
        second form sets the state to the specified value. If you passed state=0
        , the constructor uses the above default value instead to avoid the
        singular random number sequence, consisting of all zeros.
        
        RNG();
        /**@overload
        @param state 64-bit value used to initialize the RNG.
        
        RNG(uint64 state);
        /**The method updates the state using the MWC algorithm and returns the
    
        **********************************************************/
    
        RNG rng(0xFFFFFFFF); 
        /**********************************************************
        @brief Returns a zero array of the specified size and type.

        The method returns a Matlab-style zero array initializer. It can be used to quickly form a constant
        array as a function parameter, part of a matrix expression, or as a matrix initializer. :
        @code
            Mat A;
            A = Mat::zeros(3, 3, CV_32F);
        @endcode
        In the example above, a new matrix is allocated only if A is not a 3x3 floating-point matrix.
        Otherwise, the existing matrix A is filled with zeros.
        @param rows Number of rows.
        @param cols Number of columns.
        @param type Created matrix type.
        ************************************************************/
        Mat image = Mat::zeros(height, width, CV_8UC3);
    
        /************************************************************
        @brief Displays an image in the specified window.

        The function imshow displays an image in the specified window. If the window was created with the
        cv::WINDOW_AUTOSIZE flag, the image is shown with its original size, however it is still limited by the screen resolution.
        Otherwise, the image is scaled to fit the window. The function may scale the image, depending on its depth:

        -   If the image is 8-bit unsigned, it is displayed as is.
        -   If the image is 16-bit unsigned or 32-bit integer, the pixels are divided by 256. That is, the
            value range [0,255\*256] is mapped to [0,255].
        -   If the image is 32-bit floating-point, the pixel values are multiplied by 255. That is, the
            value range [0,1] is mapped to [0,255].

        If window was created with OpenGL support, cv::imshow also support ogl::Buffer , ogl::Texture2D and
        cuda::GpuMat as input.

        If the window was not created before this function, it is assumed creating a window with cv::WINDOW_AUTOSIZE.

        If you need to show an image that is bigger than the screen resolution, you will need to call namedWindow("", WINDOW_NORMAL) before the imshow.

        @note This function should be followed by cv::waitKey function which displays the image for specified
        milliseconds. Otherwise, it won't display the image. For example, **waitKey(0)** will display the window
        infinitely until any keypress (it is suitable for image display). **waitKey(25)** will display a frame
        for 25 ms, after which display will be automatically closed. (If you put it in a loop to read
        videos, it will display the video frame-by-frame)

        @note

        [__Windows Backend Only__] Pressing Ctrl+C will copy the image to the clipboard.

        [__Windows Backend Only__] Pressing Ctrl+S will show a dialog to save the image.

        @param winname Name of the window.
        @param mat Image to be shown.
        *************************************************************************/
        imshow(wndname, image);
        
        /*************************************************************************
        @brief Waits for a pressed key.
        The function waitKey waits for a key event infinitely (when \f$\texttt{delay}\leq 0\f$ ) or for delay
        milliseconds, when it is positive. Since the OS has a minimum time between switching threads, the
        function will not wait exactly delay ms, it will wait at least delay ms, depending on what else is
        running on your computer at that time. It returns the code of the pressed key or -1 if no key was
        pressed before the specified time had elapsed.

        @note

        This function is the only method in HighGUI that can fetch and handle events, so it needs to be
        called periodically for normal event processing unless HighGUI is used within an environment that
        takes care of event processing.

        @note

        The function only works if there is at least one HighGUI window created and the window is active.
        If there are several HighGUI windows, any of them can be active.

        @param delay Delay in milliseconds. 0 is the special value that means "forever".
        *********************************************************************************/
        waitKey(DELAY);
    
    
        for( i=0; i < NUMBER; i++){
                Point pt1, pt2;
                pt1.x = rng.uniform(x1, x2);
                pt1.y = rng.uniform(y1, y2);
                pt2.x = rng.uniform(x1, x2);
                pt2.y = rng.uniform(y1, y2);
                /************************************************************************
                @brief Draws a line segment connecting two points.

                The function line draws the line segment between pt1 and pt2 points in the image. The line is
                clipped by the image boundaries. For non-antialiased lines with integer coordinates, the 8-connected
                or 4-connected Bresenham algorithm is used. Thick lines are drawn with rounding endings. Antialiased
                lines are drawn using Gaussian filtering.

                @param img Image.
                @param pt1 First point of the line segment.
                @param pt2 Second point of the line segment.
                @param color Line color.
                @param thickness Line thickness.
                @param lineType Type of the line, see cv::LineTypes.
                @param shift Number of fractional bits in the point coordinates.
                ***********************************************************************************/
                line( image , pt1, pt2, randomColor(rng), rng.uniform(1, 10), lineType);
                imshow(wndname, image);
                if(waitKey(DELAY) >= 0)
                        return 0;
        }
        waitKey();
        return 0;
}

static void help()
{
    printf("\nThis program demonstrates OpenCV drawing and text output functions.\n"
    "Usage:\n"
    "   ./drawing\n");
}
static Scalar randomColor(RNG& rng)
{
    int icolor = (unsigned)rng;
    return Scalar(icolor&255, (icolor>>8)&255, (icolor>>16)&255);
}



    
    
    
    
