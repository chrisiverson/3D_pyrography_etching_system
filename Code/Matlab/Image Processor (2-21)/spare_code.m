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