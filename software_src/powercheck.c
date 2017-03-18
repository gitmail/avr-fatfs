#include "config.h"
/*电量检测初始化
*设置端口
*初始化关闭
*/
void power_check_init(void){
	
		POWER_DDR_SET();
		config.is_lowpower = 0;
}	

/*继电器控制
*传入 ： 温度
*传出 ： 当前继电器状态
*
*/
void power_state_refresh(void)
{
 	 //电池状态刷新 刷新依据：PINE_4没电高电平 有电低电平
    //
	config.is_lowpower = POWER_PIN_READ();

	if(config.is_lowpower) {
	    LED_ON();
	}
	else {
	    LED_OFF();
	}
	return ;
}