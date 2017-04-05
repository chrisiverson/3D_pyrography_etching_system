function [ x, y, x_coor, y_coor, next_x, next_y ] = image_2_machine( Im_please_work, start_x, start_y )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
[p,q] = find(Im_please_work);

[X,Y] = size(Im_please_work);

starting_point = [start_x,start_y];

x_coor = zeros(length(p),1);
y_coor = zeros(length(p),1);

x_coor(1) = start_x;
y_coor(1) = start_y;

%infill_follow = 0;

next_x = 1;
next_y = 1;

for l = 2:length(p)+1

dis_tot_save = inf;

if (y_coor(l-1) < Y) && (l > 1) && (Im_please_work(x_coor(l-1),y_coor(l-1)+1) == 1)
        next_x = x_coor(l-1);
        next_y = y_coor(l-1)+1;
else
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

