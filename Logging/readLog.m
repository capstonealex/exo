close all; clear; 
format long g
C = csvread('ALEXLOG_TESTING_0304.csv');
m = getMotorSpecs;
raw2torque = m.nominalTorque/1000;        % 0.319 [Nm] in the datasheet
torqueConstant    = m.torqueConstant;   % in [Nm/A] from Maxon - 412825 datasheet

timePerc        = C(:,1)-C(1,1);
LHipActPos      = C(:,2);
LHipDesPos      = C(:,3);
LHipActTorq     = C(:,4);
LKneeActPos      = C(:,5);
LKneeDesPos      = C(:,6);
LKneeActTorq     = C(:,7);
RHipActPos      = C(:,8);
RHipDesPos      = C(:,9);
RHipActTorq     = C(:,10);
RKneeActPos      = C(:,11);
RKneeDesPos      = C(:,12);
RKneeActTorq     = C(:,13);
LAnkActPos      = C(:,14);
LAnkDesPos      = C(:,15);
LAnkpActTorq     = C(:,16);
RAnkActPos      = C(:,17);
RAnkDesPos      = C(:,18);
RAnkpActTorq     = C(:,19);

LHipActCurrent = LHipActTorq*raw2torque/torqueConstant;
RHipActCurrent = RHipActTorq*raw2torque/torqueConstant;
LKneeActCurrent = LKneeActTorq*raw2torque/torqueConstant;
RKneeActCurrent = RKneeActTorq*raw2torque/torqueConstant;

tot_current = (abs(RHipActCurrent)+abs(LHipActCurrent)+abs(RKneeActCurrent)+abs(LKneeActCurrent));
maxCurrent = 18;
highDriverCurrent = 5;

% idx=find(timePerc>100&timePerc<timePerc(end));
idx=find(timePerc>1500&timePerc<1600);
idx_maxCurrent = find((tot_current>maxCurrent)&((LHipActCurrent>highDriverCurrent)...
    |(RHipActCurrent>highDriverCurrent)|(LKneeActCurrent>highDriverCurrent)|...
    (RKneeActCurrent>highDriverCurrent)));

figure('Name','Current and pos from RHip motor','NumberTitle','off');
subplot(2,1,1)
plot(timePerc(idx),RHipActCurrent(idx))
hold on
plot(timePerc(idx),-m.maxCurrentDrivers*ones(length(idx),1),'--r')
plot(timePerc(idx),m.maxCurrentDrivers*ones(length(idx),1),'--r')
axis([timePerc(idx(1)) timePerc(idx(end)) -6.2 6.2])
subplot(2,1,2)
plot(timePerc(idx),RHipActPos(idx),'LineWidth',1.5)
hold on
plot(timePerc(idx),RHipDesPos(idx))

figure('Name','Current and pos from LHip motor','NumberTitle','off');
subplot(2,1,1)
plot(timePerc(idx),LHipActCurrent(idx))
hold on
plot(timePerc(idx),-m.maxCurrentDrivers*ones(length(idx),1),'--r')
plot(timePerc(idx),m.maxCurrentDrivers*ones(length(idx),1),'--r')
axis([timePerc(idx(1)) timePerc(idx(end)) -6.2 6.2])
legend('Current (A)','Current Limit (A)')
subplot(2,1,2)
plot(timePerc(idx),LHipActPos(idx),'LineWidth',1.5)
hold on
plot(timePerc(idx),LHipDesPos(idx))

figure('Name','Current and pos from RKnee motor','NumberTitle','off');
subplot(2,1,1)
plot(timePerc(idx),RKneeActCurrent(idx))
hold on
plot(timePerc(idx),-m.maxCurrentDrivers*ones(length(idx),1),'--r')
plot(timePerc(idx),m.maxCurrentDrivers*ones(length(idx),1),'--r')
axis([timePerc(idx(1)) timePerc(idx(end)) -6.2 6.2])
subplot(2,1,2)
plot(timePerc(idx),RKneeActPos(idx),'LineWidth',1.5)
hold on
plot(timePerc(idx),RKneeDesPos(idx))

figure('Name','Current and pos from LKnee motor','NumberTitle','off');
subplot(2,1,1)
plot(timePerc(idx),LKneeActCurrent(idx))
hold on
plot(timePerc(idx),-m.maxCurrentDrivers*ones(length(idx),1),'--r')
plot(timePerc(idx),m.maxCurrentDrivers*ones(length(idx),1),'--r')
axis([timePerc(idx(1)) timePerc(idx(end)) -6.2 6.2])
subplot(2,1,2)
plot(timePerc(idx),LKneeActPos(idx),'LineWidth',1.5)
hold on
plot(timePerc(idx),LKneeDesPos(idx))

figure('Name','Total Current from all motors','NumberTitle','off');
plot(timePerc(idx),tot_current(idx))

% figure('Name','Max Total Current from all motors','NumberTitle','off');
% plot(timePerc(idx_maxCurrent),tot_current(idx_maxCurrent),'o')
