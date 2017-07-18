


double alpha;
        int beta;
        Mat image = imread("/home/security/project/opencv2.1/kuka.jpg");
        Mat new_image =  Mat::zeros(image.size(), image.type());
        ///Initialize values
        cout << " Basic Linear Transforms "<< endl;
        cout << "-------------------------"<< endl;
        cout << "Enter the alpha valuer [1.0 - 3.0]:"; cin >> alpha;
        cout << "Enter the beta value [0-100]:"; cin >> beta;
        for(int y = 0; y < image.rows; y++){
                for(int x = 0; x < image.cols; x++){
                        for(int c=0; c<3; c++){
                                new_image.at<Vec3b>(y, x)[c] =
                                        saturate_cast<uchar>(alpha*(image.at<Vec3b>(y, x)[c]) + beta);
                        }
                }
        }

        namedWindow("Original Image", 1);
        namedWindow("New Image", 1);

        imshow("Original Image", image);
        imshow("New Image", new_image);
        waitKey(0);

        return 0;
}

                     
