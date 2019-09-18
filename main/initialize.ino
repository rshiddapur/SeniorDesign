/**
 * This file provides a quick sanity check that
 * the robot is working.
 */

     void initialize()
    {
        // Set the head looking to the side.
        head.write(0);
        delay(2000);
        // Set the head looking to the other side.
        head.write(180);
        delay(2000);
        // and to the middle
        head.write(90);
        delay(1000);

        getDistance();
        
        // do a little dance
        // test turning forward left
        motor('L',1);
        // test turning backward left
        motor('l',2);
        // test turning forward left
        motor('L',1);
        // test turning forward right
        motor('R',1);
        // test turning backward right
        motor('r',2);
        // test turning forward right
        motor('R',1);
        // test moving straight forward
        motor('S',1);
        // test moving straight backward
        motor('s',2);
        // test moving straight forward
        motor('S',1);
        // test turning clockwise (to the right)
        motor('C',7);
        // test turning counter-clockwise (to the left)
        motor('c',14);
        // test turning clockwise (to the right)
        motor('C',8);
    }

