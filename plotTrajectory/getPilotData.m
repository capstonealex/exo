function pilot = getPilotData()
    % All measurements in meters and kg
    p.torso.length      =    0.4;
    p.torso.mass        =   40;
    p.torso.radius      =    0.2;    % For inertia
    
    p.hip.width         =    0.4;
    p.hip.depth         =    0.4;
     
    p.leg_up.length     =    0.46;
%     p.leg_up.length = 0.43;
    p.leg_up.radius     =    0.1;    % For inertia
    p.leg_up.mass       =   8;
  
    p.leg_low.length    =    0.43;
%     p.leg_low.length = 0.37;
    p.leg_low.radius    =    0.08;   % For inertia
    p.leg_low.mass      =    4; 
    
    p.foot.length       =    0.30;
    p.foot.radius       =    0.05;   % For inertia 
    p.foot.ankle_height =    0.12;  
%     p.foot.ankle_height = 0.095;
    p.foot.mass         =    1;
    
    p.buttocks          =    0.12;   
    p.mass              =   2*p.foot.mass + 2* p.leg_low.mass + 2*p.leg_up.mass + p.torso.mass ;
    
    pilot = p;
end