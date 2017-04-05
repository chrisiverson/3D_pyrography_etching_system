function [ x, y, x_coor, y_coor, next_x, next_y ] = image_2_machine( Im_please_work, start_x, start_y )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
[p,q] = find(Im_please_work);

[X,Y] = size(Im_please_work);

starting_point = [start_x,start_y];

for l = 1:length(p)

next_x = 1;
next_y = 1;

dis_tot_save = 50000;

for i = 1:X
    for j = 1:Y
        if (Im_please_work(i,j) == 1) 
            distance_x = i - starting_point(1);
            distance_y = starting_point(2) - j;
            dis_tot = sqrt(distance_x^2 + distance_y^2);
            
            if dis_tot < dis_tot_save
                dis_tot_save = dis_tot;
                next_x = i;
                next_y = j;
            end
        end
    end
end

Im_please_work(next_x,next_y) = 0;

x(l) = next_x-starting_point(1);
y(l) = next_y-starting_point(2);

x_coor(l) = next_x;
y_coor(l) = next_y;

starting_point(1) = next_x;
starting_point(2) = next_y;

end
end

