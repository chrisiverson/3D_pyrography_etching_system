function [] = write_2_file( x_moves_3, y_moves_3, fileID, first )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
j = 0;
f = 3;

for i = 1:length(x_moves_3)

        
     if (y_moves_3(i) > 1) || (y_moves_3(i) < -1) || (x_moves_3(i) > 1) || (x_moves_3(i) < -1)
         if first == 0
                fprintf(fileID,',');
         else
                first = 0;
         end
         
         fprintf(fileID,' B100000');
         
         if (y_moves_3(i) > 1)
             fprintf(fileID, '0');
         else
             fprintf(fileID, '1');
         end
         
         if (x_moves_3(i) > 1)
             fprintf(fileID, '0');
         else
             fprintf(fileID, '1');
         end
         %abs(y_moves_3(i));
         binary_y=de2bi(abs(y_moves_3(i)),8);
         binary_x=de2bi(abs(y_moves_3(i)),8);
         
         fprintf(fileID,', B');
         for o = 1:8
             
             fprintf(fileID,'%1i',binary_y(9-o));
             %binary_y(o)
         end
         fprintf(fileID,', B');
         for o = 1:8
             fprintf(fileID,'%1i',binary_x(9-o));
         end
         f = 3;
         fprintf(fileID,'');
     else
        if (f/3) == 1
            if first == 0
                fprintf(fileID,',');
            else
                first = 0;
            end
            fprintf(fileID,' B00');
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

end

