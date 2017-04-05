function [ x_fin, y_fin, x_move, y_move, final_x, final_y, num_steps ] = conv_to_moves( Im_array, current_x, current_y )
%CONV_TO_MOVES Summary of this function goes here
%   Detailed explanation goes here
%Convert the image into an ordered image based on shade and proximity to the origin 0,0
[X,Y] = size(Im_array);
Im_outline= Im_array;
Im_zeros = zeros(X,Y);

sum_Im = sum(sum((Im_outline)));
sum_4_loop = sum_Im;
num_steps = sum_Im;
    
%Nearest point search
starting_point = [current_x,current_y];
dis_tot_save = 50000;
dis_tot = 0;
next_x = 1;
next_y = 1;

%i = 1;
%j = 150;

%Nearest point search
for i = 1:X
    for j = 1:Y
        if (Im_outline(i,j) == 1) 
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

dis_tot_save;
next_x;
next_y;


x_fin = zeros(num_steps,1);
y_fin = zeros(num_steps,1);
x_move = zeros(num_steps,1);
y_move = zeros(num_steps,1);

x_fin(1,1)=next_x;
x_move(1,1) = next_x;
y_fin(1,1)=next_y;
y_move(1,1)=Y-next_y;
Im_outline(next_x,next_y) = 0;


for i = 1:num_steps
    if (x_fin(i) < X)    % | y_fin(i) ~= 0 | x_fin(i) ~= X | y_fin(i) ~= Y)
        if Im_outline(x_fin(i)+1,y_fin(i))
            next_x = x_fin(i)+1;
            next_y = y_fin(i);
        end
    end
    if (y_fin(i) < Y) & (x_fin(i) < X)
    if Im_outline(x_fin(i)+1,y_fin(i)+1)
        next_x = x_fin(i)+1;
        next_y = y_fin(i)+1;
    end
    end
    if (y_fin(i) < Y)
    if Im_outline(x_fin(i),y_fin(i)+1)
        next_x = x_fin(i);
        next_y = y_fin(i)+1;
    end
    end
    if (x_fin(i) > 1)
    if Im_outline(x_fin(i)-1,y_fin(i))
        next_x = x_fin(i)-1;
        next_y = y_fin(i);
    end
    end
    if (y_fin(i) > 1)
    if Im_outline(x_fin(i),y_fin(i)-1)
        next_x = x_fin(i);
        next_y = y_fin(i)-1;
    end
    end
    if (x_fin(i) > 1) & (y_fin(i) > 1)
    if Im_outline(x_fin(i)-1,y_fin(i)-1)
        next_x = x_fin(i)-1;
        next_y = y_fin(i)-1;
    end
    end
    if (x_fin(i) > 1) & (y_fin(i) < Y)
    if Im_outline(x_fin(i)-1,y_fin(i)+1)
        next_x = x_fin(i)-1;
        next_y = y_fin(i)+1;
    end
    end
    if (x_fin(i) < X) & (y_fin(i) > 1)
    if Im_outline(x_fin(i)+1,y_fin(i)-1)
        next_x = x_fin(i)+1;
        next_y = y_fin(i)-1;
    end
    end
    x_fin(i+1) = next_x;%-x_fin(i);
    x_move(i+1) = next_x-x_fin(i);
    y_fin(i+1) = next_y;%-y_fin(i);
    y_move(i+1) = (Y-next_y)-(Y-y_fin(i));
    Im_outline(next_x,next_y) = 0;
end
final_x=sum(x_fin);
final_y=sum(y_fin);
end