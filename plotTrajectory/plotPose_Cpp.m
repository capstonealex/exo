%close all; clear; 
figure
pilot = getPilotData;

fileID = fopen('sit to stand.csv');
C = textscan(fileID,'%f, %f, %f, %f, %f, %f, %f,');
fclose(fileID);

timePerc        = C{1};
LHip            = C{2};
LKnee           = C{3};
RHip            = C{4};
RKnee           = C{5};
LAnkle          = C{6};
RAnkle          = C{7};

Q1 = deg2rad(RAnkle);
Q2 = deg2rad(RKnee);
Q3 = deg2rad(RHip);
Q4 = deg2rad(LHip);
Q5 = deg2rad(LKnee);
Q6 = deg2rad(LAnkle);

Q1 = deg2rad(95)*ones(21,1);
Q6 = deg2rad(95)*ones(21,1);

Q = [Q1 Q2 Q3 Q4 Q5 Q6];
%tiledlayout(5,5) % Requires R2019b or later
for i = 1:size(Q,1)
%nexttile
RHipPos = [0-pilot.leg_low.length*cos(Q1(i))- ...
    pilot.leg_up.length*(cos(Q1(i)-Q2(i)))   0       pilot.foot.ankle_height + ...
    pilot.leg_low.length*sin(Q1(i))+pilot.leg_up.length*(sin(Q1(i) - Q2(i)))];

RKneePos = [pilot.leg_low.length*cos(pi-Q1(i)) 
                            0 
            pilot.foot.ankle_height+pilot.leg_low.length*sin(pi-Q1(i))];
LHipPos = RHipPos;

LKneePos = [LHipPos(1)+pilot.leg_up.length*sin(pi-Q4(i)-(pi/2+Q1(i)-Q2(i)-Q3(i))) 
                                                0 
            LHipPos(3)-pilot.leg_up.length*cos(pi-Q4(i)-(pi/2+Q1(i)-Q2(i)-Q3(i)))];
LAnklePos = [LKneePos(1)-pilot.leg_low.length*cos(1.5*pi-(pi/2+Q1(i)-Q2(i)-Q3(i))-Q4(i)-Q5(i))
                                                0
             LKneePos(3)-pilot.leg_low.length*sin(1.5*pi-(pi/2+Q1(i)-Q2(i)-Q3(i))-Q4(i)-Q5(i))];
Torso = [RHipPos(1)+pilot.torso.length*sin((pi/2+Q1(i)-Q2(i)-Q3(i))) 
                                        0 
         RHipPos(3)+pilot.torso.length*cos((pi/2+Q1(i)-Q2(i)-Q3(i)))];
hold on
plot([0 RKneePos(1) RHipPos(1) Torso(1)],[pilot.foot.ankle_height RKneePos(3) RHipPos(3) Torso(3)],'-o');
plot([Torso(1) RHipPos(1) LKneePos(1) LAnklePos(1)],[Torso(3) RHipPos(3) LKneePos(3) LAnklePos(3)],'-o');

daspect([1 1 1])
axis([-1.0 1.0 0 1.8])
end



