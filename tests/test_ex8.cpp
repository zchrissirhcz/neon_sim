#include <iostream>


#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif


int main()
{
    int i,j;
    //src is 3*32
    uint8_t src[]={9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6,9,8,6};
    uint8x8_t rfac = vdup_n_u8 (77);
    uint8x8_t gfac = vdup_n_u8 (151);
    uint8x8_t bfac = vdup_n_u8 (28);
    unsigned int n=96;//n=32*3
    n/=24;

    for(j=0;j<10;j++)
    {
        for (i=0; i<n; i++)//n=3
        {
            uint16x8_t  temp;
            uint8x8x3_t rgb=vld3_u8(&src[i*24]);

            temp = vmull_u8 (rgb.val[0],      rfac);
            temp = vmlal_u8 (temp,rgb.val[1], gfac);
            temp = vmlal_u8 (temp,rgb.val[2], bfac);
            //  src  += 8*3;    
    
            //printf("now is %d------temp = %d\n",j, temp);
            std::cout << "j = " << j << ", temp = " << temp << std::endl;
        }
    }
    printf("neon ts is Done !!\n");
}