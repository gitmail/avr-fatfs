#include "config.h"
/*继电器初始化
*设置端口
*初始化关闭
*/
void relay_init(void){
	
		RELAY_DDR_SET() ;
		RELAY_OFF();
		//state.Relay = 0;
	}	

/*继电器控制
*传入 ： 温度
*传出 ： 当前继电器状态
*
*/
unsigned char  relay(int temp)
{
	if(temp<HEAT_THRESHOLD)
	{
	 		RELAY_DDR_SET();
			RELAY_ON();
			//state.Relay = 1 ;
	}
	else
	{
	 	RELAY_DDR_SET();
		RELAY_OFF();
		//state.Relay = 0 ;
	}		
	//return state.Relay;
	return 0;
}