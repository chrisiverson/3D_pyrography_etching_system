[x_move_2, y_move_2, x_fin_2, y_fin_2, final_x_2, final_y_2, num_steps_2 ] = conv_to_moves( (Im_array_outlabel_2 == 1), 1, Y);

x_move_2
y_move_2
x_fin_2
y_fin_2
final_x_2
final_y_2
num_steps_2

figure
plot(x_fin_2,y_fin_2)
grid on


[B,L] = bwboundaries(Im_array_1,'noholes');
imshow(label2rgb(L, @jet, [.5 .5 .5]))
hold on
for k = 1:length(B)
   boundary = B{k};
   plot(boundary(:,2), boundary(:,1), 'w', 'LineWidth', 2)
end

i = 1;

[x_move_1, y_move_1, x_fin_1, y_fin_1, final_x_1(1), final_y_1(1), num_steps_1 ] = conv_to_moves( (Im_array_outlabel_1 == i),final_x_2, final_y_2);

cat_array_x = cat(2,x_move_1,y_move_1)
%cat_array_y = cat(1,y_move_1)


%for i = 2:num_objects_1_out
    i = 2;
    [x_move_1, y_move_1, x_fin_1, y_fin_1, final_x_1(i), final_y_1(i), num_steps_1 ] = conv_to_moves( (Im_array_outlabel_1 == i),final_x_1(i-1), final_y_1(i-1));
    x_move_1
    y_move_1
    x_fin_1
    y_fin_1
    %cat_array_x = cat(3,cat_array_x,x_move_1)
    %cat_array_y = cat(3,cat_array_y,y_move_1)
    %x_fins(i,:) = x_fin_1;
    %y_fins(i,:) = y_fin_1;
    
%end

figure
plot(x_fin_2,y_fin_2)
grid on







%******************Image_2_file early beta code
j = 0;
f = 3;

for i = 1:length(x_moves_3)
    

        
     if (y_moves_3(i) > 1) || (y_moves_3(i) < -1) || (x_moves_3(i) > 1) || (x_moves_3(i) < -1)
         fprintf(fileID,' B100000');
         
         if (y_moves_3(i) > 1)
             fprintf(fileID, '0');
         else
             fprintf(fileID, '1');
         end
         
         if (x_moves_3(i) > 1)
             fprintf(fileID, '0,');
         else
             fprintf(fileID, '1,');
         end
         %abs(y_moves_3(i));
         binary_y=de2bi(abs(y_moves_3(i)),8);
         binary_x=de2bi(abs(y_moves_3(i)),8);
         
         fprintf(fileID,' B');
         for o = 1:8
             fprintf(fileID,'%1i',binary_y(9-o));
             %binary_y(o)
         end
         fprintf(fileID,', B');
         for o = 1:8
             fprintf(fileID,'%1i',binary_x(9-o));
         end
     else
        if (f/3) == 1
            fprintf(fileID,', B00');
            f = 1;
        else
            f = f+1;
        end
        
         if (y_moves_3(i) == 1) && (x_moves_3(i) == 1) %UR
             fprintf(fileID,'11');
         elseif (y_moves_3(i) == 1) && (x_moves_3(i) == -1) %UL
             fprintf(fileID,'10');
         elseif (y_moves_3(i) == -1) && (x_moves_3(i) == 1) %DR
             fprintf(fileID,'01');
         elseif (y_moves_3(i) == -1) && (x_moves_3(i) == -1) %DL
             fprintf(fileID,'00');
         end
     
     end
         

        
   
        j = j+1;
end
fprintf(fileID,'};');




for i = 1:length(x_moves_4)
    if x_moves_4(i) < 0
    fprintf(fileID,' %1i, 0',0-x_moves_4(i));
    else
    fprintf(fileID,' 0, %1i',x_moves_4(i));
    end
        fprintf(fileID,',');
    if y_moves_4(i) < 0
    fprintf(fileID,' %1i, 0',0-y_moves_4(i));
    else
    fprintf(fileID,' 0, %1i',y_moves_4(i));
    end
    if (num_steps ~= i)

        fprintf(fileID,',');
    end
end

for i = 1:length(x_moves_2)
    if x_moves_2(i) < 0
    fprintf(fileID,' %1i, 0',0-x_moves_2(i));
    else
    fprintf(fileID,' 0, %1i',x_moves_2(i));
    end
        fprintf(fileID,',');
    if y_moves_2(i) < 0
    fprintf(fileID,' %1i, 0',0-y_moves_2(i));
    else
    fprintf(fileID,' 0, %1i',y_moves_2(i));
    end
    if (num_steps ~= i)

        fprintf(fileID,',');
    end
end

for i = 1:length(x_moves)
    if x_moves(i) < 0
    fprintf(fileID,' %1i, 0',0-x_moves(i));
    else
    fprintf(fileID,' 0, %1i',x_moves(i));
    end
        fprintf(fileID,',');
    if y_moves(i) < 0
    fprintf(fileID,' %1i, 0',0-y_moves(i));
    else
    fprintf(fileID,' 0, %1i',y_moves(i));
    end
    if (num_steps ~= i)

        fprintf(fileID,',');
    end
end
fprintf(fileID,'};\n');