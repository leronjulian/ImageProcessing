//
//  main.cpp
//  Image Processing Project
//
//  Created by Leron Julian on 11/2/16.
//  Copyright © 2016 Leron Julian. All rights reserved.
//

/*
 Create an image processing Class that does the following five tasks on images
 
 1.Convert a Black and White image to Color
 2.Convert a Color image to Black and White
 3.Subtract the background from an image and replace the background with the color White.
 4.Replace the background of an image with another image
 5.Blend two images together
 
Additional Instructions
 
 All images will be in PPM formate.
 Create a menu that allows the user to select which of the 5 task to do.
 Allow user to upload their own images
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "ImageProcessing.h"

using namespace std;

struct RGBValues{
    int R,G,B;
};


ifstream& operator >>(ifstream &in,RGBValues &RGBV){
    in >> RGBV.R;
    in >> RGBV.G;
    in >> RGBV.B;
    return in;
}

void toBlack(RGBValues *data, colorToGray &tograyClass);
void toColorFunct(RGBValues *data2, grayToColor &tocolorClass2);
void toWhite(RGBValues *dataPicture1, RGBValues *dataPicture2, backgroundToWhite &towhiteClass);
void newBackground(RGBValues *forefrontPic, RGBValues *backPic, backgroundToImage &changeBackground);
void toBlend(RGBValues *originalPic, RGBValues *secondPic, blendImages &toblend);

int main() {
    int choice;
    cout << "Enter 1 to convert image to gray: " << endl;
    cout << "Enter 2 to convert image to color: " << endl;
    cout << "Enter 3 to replace the backround to all white: " << endl;
    cout << "Enter 4 to replace the background with another image: " << endl;
    cout << "Enter 5 to blend two images together: " << endl;
    
    do{
        cout << "Enter number: ";
        cin >> choice;
        cout << endl;
        cout << endl;
    }while(choice < 1 || choice > 6);
    
    //Convert to Gray
    if(choice == 1){
        colorToGray toGray;
        ifstream originalPhoto;
        string file_upload;
        cout << "Enter the name of the picture (Ex. Name.ppm): ";
        cin >> file_upload;
        originalPhoto.open(file_upload);
        cout << endl;
        cout << "Opening " << file_upload << "...." << endl;
        
        string temp;
        int height, width, hue;
        getline(originalPhoto, temp);
        getline (originalPhoto, temp);
        originalPhoto >> height;
        toGray.setColorHeight(height);
        originalPhoto >> width;
        toGray.setColorWidth(width);
        originalPhoto >> hue;
        toGray.setColorHue(hue);
        
        const int num = toGray.colorArea();
        RGBValues *RGB = new RGBValues[num];
        
        if (originalPhoto.is_open())
        {
            string line;
            for(int i = 0; i < 4; i++){
                getline(originalPhoto, line);
            }
            int count = 0;
            while(count < (toGray.colorArea())){
                originalPhoto >> RGB[count].R;
                originalPhoto >> RGB[count].G;
                originalPhoto >> RGB[count].B;
                count++;
            }
            toBlack(RGB, toGray);
        }
        else cout << "Unable to open file" << endl;
    }
    
    //Converts to color
    else if(choice == 2){
        grayToColor toColor;
        ifstream originalPhoto;
        string file_upload;
        cout << "Enter the name of the picture (Ex. Name.ppm): ";
        cin >> file_upload;
        originalPhoto.open(file_upload);
        cout << endl;
        cout << "Opening " << file_upload << "...." << endl;
        
        string temp;
        int height, width, hue;
        getline(originalPhoto, temp);
        getline (originalPhoto, temp);
        originalPhoto >> height;
        toColor.setGrayHeight(height);
        originalPhoto >> width;
        toColor.setGrayWidth(width);
        originalPhoto >> hue;
        toColor.setGrayHue(hue);
        
        const int num = toColor.grayArea();
        RGBValues *RGB = new RGBValues[num];
        
        if (originalPhoto.is_open())
        {
            string line;
            for(int i = 0; i < 4; i++){
                getline(originalPhoto, line);
            }
            int count = 0;
            while(count < (toColor.grayArea())){
                originalPhoto >> RGB[count].R;
                originalPhoto >> RGB[count].G;
                originalPhoto >> RGB[count].B;
                count++;
            }
            toColorFunct(RGB, toColor);
        }
        else cout << "Unable to open file" << endl;
    }
    
    //Replace the background to all white
    else if(choice == 3){
        backgroundToWhite toWhiteClass;
        ifstream picture1, picture2;
        string picture1Upload, picture2Upload;
        
        cout << "Enter the name of the whole picture (Ex. Name.ppm): ";
        cin >> picture1Upload;
        picture1.open(picture1Upload);
        
        cout << endl;
        cout << "Opening " << picture1Upload << "...." << endl;
        cout << endl;
        cout << "Enter the name just the background picture (Ex. Name.ppm): ";
        cin >> picture2Upload;
        picture2.open(picture2Upload);
        
        string temp;
        int height, width, hue;
        
        getline(picture1, temp);
        getline (picture1, temp);
        picture1 >> height;
        toWhiteClass.setimgHeight(height);
        picture1 >> width;
        toWhiteClass.setimgWidth(width);
        picture1 >> hue;
        toWhiteClass.setimgHue(hue);
        
        const int num = toWhiteClass.getimgArea();
        RGBValues *RGB = new RGBValues[num];
        RGBValues *RGB2 = new RGBValues[num];
        
        if (picture1.is_open() && picture2.is_open())
        {
            string line;
            for(int i = 0; i < 4; i++){
                getline(picture1, line);
                getline(picture2, line);
            }
            int count = 0;
            while(count < (toWhiteClass.getimgArea())){
                picture1 >> RGB[count].R;
                picture2 >> RGB2[count].R;
                
                picture1 >> RGB[count].G;
                picture2 >> RGB2[count].G;
                
                picture1 >> RGB[count].B;
                picture2 >> RGB2[count].B;
                count++;
            }
            toWhite(RGB, RGB2, toWhiteClass);
        }
        else cout << "Unable to open file" << endl;
    }
    
    //Replaces the background with another image
    else if (choice == 4){
        backgroundToImage imgbckground;
        ifstream picture1, picture2;
        string picture1Upload, picture2Upload;
        
        cout << "Enter the name of the whole picture (Ex. Name.ppm): ";
        cin >> picture1Upload;
        picture1.open(picture1Upload);
        
        cout << endl;
        cout << "Opening " << picture1Upload << "...." << endl;
        cout << endl;
        cout << "Enter the name just the background picture (Ex. Name.ppm): ";
        cin >> picture2Upload;
        picture2.open(picture2Upload);
        
        string temp;
        int height, width, hue;
        
        getline(picture1, temp);
        getline (picture1, temp);
        picture1 >> height;
        imgbckground.setOrgHeight(height);
        picture1 >> width;
        imgbckground.setOrgWidth(width);
        picture1 >> hue;
        imgbckground.setOrgHue(hue);
        
        const int num = imgbckground.getOrgArea();
        RGBValues *RGB = new RGBValues[num];
        RGBValues *RGB2 = new RGBValues[num];
        
        if (picture1.is_open() && picture2.is_open())
        {
            string line;
            for(int i = 0; i < 4; i++){
                getline(picture1, line);
                getline(picture2, line);
            }
            int count = 0;
            while(count < (imgbckground.getOrgArea())){
                picture1 >> RGB[count].R;
                picture2 >> RGB2[count].R;
                
                picture1 >> RGB[count].G;
                picture2 >> RGB2[count].G;
                
                picture1 >> RGB[count].B;
                picture2 >> RGB2[count].B;
                count++;
            }
        }
        newBackground(RGB, RGB2, imgbckground);
    }
    
    //Blends to images together
    else if (choice == 5){
        blendImages blendPic;
        ifstream picture1, picture2;
        string picture1Upload, picture2Upload;
        
        cout << "Enter the name of the whole picture (Ex. Name.ppm): ";
        cin >> picture1Upload;
        picture1.open(picture1Upload);
        
        cout << endl;
        cout << "Opening " << picture1Upload << "...." << endl;
        cout << endl;
        cout << "Enter the name just the background picture (Ex. Name.ppm): ";
        cin >> picture2Upload;
        picture2.open(picture2Upload);
        
        string temp;
        int height, width, hue;
        
        getline(picture1, temp);
        getline (picture1, temp);
        picture1 >> height;
        blendPic.setBlendedHeight(height);
        picture1 >> width;
        blendPic.setBlendedWidth(width);
        picture1 >> hue;
        blendPic.setBlendedHue(hue);
        
        const int num = blendPic.getBlendedArea();
        RGBValues *RGB = new RGBValues[num];
        RGBValues *RGB2 = new RGBValues[num];
        
        if (picture1.is_open() && picture2.is_open())
        {
            string line;
            for(int i = 0; i < 4; i++){
                getline(picture1, line);
                getline(picture2, line);
            }
            int count = 0;
            while(count < (blendPic.getBlendedArea())){
                picture1 >> RGB[count].R;
                picture2 >> RGB2[count].R;
                
                picture1 >> RGB[count].G;
                picture2 >> RGB2[count].G;
                
                picture1 >> RGB[count].B;
                picture2 >> RGB2[count].B;
                count++;
            }
        }
        toBlend(RGB, RGB2, blendPic);
        
    }
    return 0;
}

void toBlack(RGBValues *data, colorToGray &toGrayClass){
    int width, height, hue, area;
    
    hue = toGrayClass.getColorHue();
    width = toGrayClass.getColorWidth();
    height = toGrayClass.getColorHeight();
    area = toGrayClass.colorArea();
    
    for(int i = 0; i < (area - 1); i++){
        int gray = (data[i].R + data[i].G + data[i].B)/3;
        data[i].R = gray;
        data[i].G = gray;
        data[i].B = gray;
    }
    ofstream blackWhitePhoto("Black&WhitePhoto.ppm");
    cout << "Converting to black & white..." << endl;
    blackWhitePhoto << "P3" << endl;
    blackWhitePhoto << "#Created by Leron Julian" << endl;
    blackWhitePhoto << height << " " << width << endl;
    blackWhitePhoto << hue << endl;
    
    for(int count = 0; count < (area - 1); count++){
        blackWhitePhoto << data[count].R << " ";
        blackWhitePhoto << data[count].G << " ";
        blackWhitePhoto << data[count].B << " ";
    }
    cout << endl;
    cout << "Done..." << endl;
    cout << "File named Black&WhitePhoto.ppm" << endl;
    blackWhitePhoto.close();
}

void toColorFunct(RGBValues *data2, grayToColor &tocolorClass2){
    int height, width, hue, area;
    height = tocolorClass2.getGrayHeight();
    width = tocolorClass2.getGrayWidth();
    hue = tocolorClass2.getGrayHue();
    area = tocolorClass2.grayArea();
    
    for(int index = 0; index < 20; index++){
        data2[5].R = (.59*data2[index].G) - (.11*data2[index].B)/(.03);
        data2[10].G = (.1*data2[index].R) + (.8*data2[index].G) + (.1*data2[index].B);
        data2[3].B = (.4*data2[index].R) + (.3*data2[index].G) + (.3*data2[index].B);
    }
    
    for(int i = 0; i < (area); i++){
        int Red = (data2[0].R - (.59*data2[i].G) - (.11*data2[i].B))/(.3);
        int Blue = (data2[0].R - (.3*data2[i].R) - .59*data2[i].G)/(.11);
        int Green = (data2[0].R - (.3*data2[i].R) - .11*data2[i].B)/(.59);
        
        data2[i].R = Red;
        data2[i].G = Green;
        data2[i].B = Blue;
    }
    ofstream colorPhoto("ColorPhoto.ppm");
    cout << endl;
    cout << "Converting to color..." << endl;
    colorPhoto << "P3" << endl;
    colorPhoto << "#Created by Leron Julian" << endl;
    colorPhoto << height << " " << width << endl;
    colorPhoto << hue << endl;
    
    for(int count = 0; count < (area - 1); count++){
        colorPhoto << data2[count].R << " ";
        colorPhoto << data2[count].G << " ";
        colorPhoto << data2[count].B << " ";
    }
    cout << endl;
    cout << "Done..." << endl;
    cout << "File named ColorPhoto.ppm" << endl;
    colorPhoto.close();
}

void toWhite(RGBValues *dataPicture1, RGBValues *dataPicture2, backgroundToWhite &towhiteClass){
    int height, width, hue, area;
    
    height = towhiteClass.getimgHeight();
    width = towhiteClass.getimgWidth();
    hue = towhiteClass.getimgHue();
    area = towhiteClass.getimgArea();
    
    //datapicture1 will be turned into white
    
    double distance;
    for(int i = 0; i < area; i++){
        distance = sqrt(pow(dataPicture1[i].R - dataPicture2[i].R, 2) + pow(dataPicture1[i].G - dataPicture2[i].G,2) + pow(dataPicture1[i].B - dataPicture2[i].B ,2));
        if((distance < 70)){
            dataPicture1[i].R = 255;
            dataPicture1[i].G = 255;
            dataPicture1[i].B = 255;
        }
    }
    cout << endl;
    ofstream whiteBackground("whitebackground.ppm");
    cout << "Changing the background to white..." << endl;
    whiteBackground << "P3" << endl;
    whiteBackground << "#Created by Leron Julian" << endl;
    whiteBackground << height << " " << width << endl;
    whiteBackground << hue << endl;
    
    for(int count = 0; count < (area - 1); count++){
        whiteBackground << dataPicture1[count].R << " ";
        whiteBackground << dataPicture1[count].G << " ";
        whiteBackground << dataPicture1[count].B << " ";
    }
    cout << "Done..." << endl;
    cout << endl;
    cout << "File named whitebackground.ppm" << endl;
    whiteBackground.close();
}

void newBackground(RGBValues *forefrontPic, RGBValues *backPic, backgroundToImage &changeBackground){
    int height, width, hue, area;
    
    height = changeBackground.getOrgHeight();
    width = changeBackground.getOrgWidth();
    hue = changeBackground.getOrgHue();
    area = changeBackground.getOrgArea();
    
    double distance;
    for(int i = 0; i < area; i++){
        distance = sqrt(pow(forefrontPic[i].R - backPic[i].R, 2) + pow(forefrontPic[i].G - backPic[i].G,2) + pow(forefrontPic[i].B - backPic[i].B ,2));
        if((distance > 115)){
            forefrontPic[i].R = backPic[i].R;
            forefrontPic[i].G = backPic[i].G;
            forefrontPic[i].B = backPic[i].B;
        }
    }

    cout << endl;
    ofstream differentBackground("newbackground.ppm");
    cout << "Changing the background..." << endl;
    differentBackground << "P3" << endl;
    differentBackground << "#Created by Leron Julian" << endl;
    differentBackground << height << " " << width << endl;
    differentBackground << hue << endl;
    
    for(int count = 0; count < (area - 1); count++){
        differentBackground << forefrontPic[count].R << " ";
        differentBackground << forefrontPic[count].G << " ";
        differentBackground << forefrontPic[count].B << " ";
    }
    cout << "Done..." << endl;
    cout << endl;
    cout << "File named newbackground.ppm" << endl;
    differentBackground.close();
    
}
void toBlend(RGBValues *originalPic, RGBValues *secondPic, blendImages &toblend){
    int height, width, hue, area;
    
    height = toblend.getBlendedHieght();
    width = toblend.getBlendedWidth();
    hue = toblend.getBlendedHue();
    area = toblend.getBlendedArea();
    
    double distance;
    for(int i = 0; i < area; i++){
        distance = sqrt(pow(originalPic[i].R - secondPic[i].R, 2) + pow(originalPic[i].G - secondPic[i].G,2) + pow(originalPic[i].B - secondPic[i].B ,2));
        if((distance > 100 && distance < 200)){
            originalPic[i].R = secondPic[i].R;
            originalPic[i].G = secondPic[i].G;
            originalPic[i].B = secondPic[i].B;
        }
    }
    
    cout << endl;
    ofstream blendedPictures("blendedimages.ppm");
    cout << "Blending Images..." << endl;
    blendedPictures << "P3" << endl;
    blendedPictures << "#Created by Leron Julian" << endl;
    blendedPictures << height << " " << width << endl;
    blendedPictures << hue << endl;
    
    for(int count = 0; count < (area - 1); count++){
        blendedPictures << originalPic[count].R << " ";
        blendedPictures << originalPic[count].G << " ";
        blendedPictures << originalPic[count].B << " ";
    }
    cout << "Done..." << endl;
    cout << endl;
    cout << "File named blendedimages.ppm" << endl;
    blendedPictures.close();
    
}
