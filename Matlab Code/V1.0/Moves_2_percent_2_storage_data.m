clc
clear all
close all

num_of_steps = [6456,3503,2893,1937,1726];
perc_arduino_memory = [321,177,147,100,90];
total_storage_bytes = [26318,14506,12066,8342,7398];

figure(1)
plot(perc_arduino_memory,num_of_steps)
xlabel('Number of Machine Steps')
ylabel('Percentage of Arduino Memory')

figure(2)
plot(total_storage_bytes,num_of_steps)
xlabel('Number of Machine Steps')
ylabel('Total Storage (Bytes)')

figure(3)
plot(total_storage_bytes,perc_arduino_memory)
xlabel('Total Storage (Bytes)')
ylabel('Percentage of Arduino Memory')

format long g

x = 1:200;
p1 =       20.46;
p2 =      -114.3;
f(x) = p1*x + p2;

f(100)


 
