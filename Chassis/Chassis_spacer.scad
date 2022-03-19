difference(){
    union(){
//    translate([2,0,0]) cube([52,10,0.2]);
    translate([2,0,0]) cube([52,2,0.2]);
    translate([2,2,0]) cylinder(h=0.2,r=2, $fn=100);
    translate([54,2,0]) cylinder(h=0.2,r=2, $fn=100);
    translate([0,2,0]) cube([56,5,0.2]);    
}
    translate([4,4,-1]) cylinder(h=2,r=1, $fn=100);
    translate([52,4,-1]) cylinder(h=2,r=1, $fn=100);
}