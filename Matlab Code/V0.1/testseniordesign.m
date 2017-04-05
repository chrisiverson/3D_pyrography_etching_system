clc
clear all

Im = imread('Part2.3.png');
Im = im2bw(Im);
sizeofpic = size(Im)
%fileID = fopen('Untitled.txt','wt');
%fprintf(fileID,'%f',Im);
%fclose(fileID);
imshow(Im)