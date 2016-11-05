//
//  ImageProcessing.h
//  Image Processing Project
//
//  Created by Leron Julian on 11/2/16.
//  Copyright © 2016 Leron Julian. All rights reserved.
//
/*
 Create an image processing Class that does the following five tasks on images
 
 Convert a Black and White image to Color
 Convert a Color image to Black and White
 Subtract the background from an image and replace the background with the color White.
 Replace the background of an image with another image
 Blend two images together
 Additional Instructions
 
 All images will be in PPM formate.
 Create a menu that allows the user to select which of the 5 task to do.
 Allow user to upload their own images
 */
#include <iostream>
using namespace std;

#ifndef ImageProcessing_h
#define ImageProcessing_h


class colorToGray{
private:
    int colorHeight, colorWidth, colorHue;
public:
    void setColorHeight(int height)
    {colorHeight = height;}
    
    void setColorWidth(int width)
    {colorWidth = width;}
    
    void setColorHue(int hue)
    {colorHue = hue;}
    
    int getColorHeight() const
    {return colorHeight;}
    
    int getColorWidth() const
    {return colorWidth;}
    
    int getColorHue() const
    {return colorHue;}
    
    int colorArea()
    {return colorWidth * colorHeight;}
    

};


class grayToColor{
private:
    int grayHeight, grayWidth, grayHue, area;
public:
    void setGrayHeight(int height)
    {grayHeight = height;}
    
    void setGrayWidth(int width)
    {grayWidth = width;}
    
    void setGrayHue(int hue)
    {grayHue = hue;}
    
    int getGrayHeight() const
    {return grayHeight;}
    
    int getGrayWidth() const
    {return grayWidth;}
    
    int getGrayHue() const
    {return grayHue;}
    
    int grayArea()
    {return grayWidth * grayHeight;}
};

class backgroundToWhite{
private:
    int imgHeight, imgWidth, imgHue;
public:
    void setimgHeight(int height)
    {imgHeight = height;}
    
    void setimgWidth(int width)
    {imgWidth = width;}
    
    void setimgHue(int hue)
    {imgHue = hue;}
    
    int getimgHeight() const
    {return imgHeight;}
    
    int getimgWidth() const
    {return imgWidth;}
    
    int getimgHue() const
    {return imgHue;}
    
    int getimgArea() const
    {return imgHeight * imgWidth;}
};

class backgroundToImage{
private:
    int originalHeight, originalWidth, originalHue;
public:
    void setOrgHeight(int height)
    {originalHeight = height;}
    
    void setOrgWidth(int width)
    {originalWidth = width;}
    
    void setOrgHue(int hue)
    {originalHue = hue;}
    
    int getOrgHeight() const
    {return originalHeight;}
    
    int getOrgWidth() const
    {return originalWidth;}
    
    int getOrgHue() const
    {return originalHue;}
    
    int getOrgArea() const
    {return originalWidth * originalHeight;}
};

class blendImages{
private:
    int blendHeight, blendWidth, blendHue;
public:
    void setBlendedHeight(int height)
    {blendHeight = height;}
    
    void setBlendedWidth(int width)
    {blendWidth = width;}
    
    void setBlendedHue(int hue)
    {blendHue = hue;}
    
    int getBlendedHieght() const
    {return blendHeight;}
    
    int getBlendedWidth() const
    {return blendWidth;}
    
    int getBlendedHue() const
    {return blendHue;}
    
    int getBlendedArea() const
    {return blendHeight * blendWidth;}
};
#endif /* ImageProcessing_h */
