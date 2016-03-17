#ifndef VARIABLES_H
#define VARIABLES_H


class variables
{
public:
    variables();

    struct values {

        // sharpening
        int alpha, beta, gamma;
        int size;
        int sigmaX;

        // contrast
        int scale, betaC;

        //morphological ops
        int thresh;
        int sSize;

        int ssSizeX, ssSizeY;

        // cropping
        double x, y;
        double width, height;
        int imRows, imCols;
    } var;
};

#endif // VARIABLES_H
