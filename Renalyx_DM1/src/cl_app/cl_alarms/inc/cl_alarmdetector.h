/*
 * cl_alarmdetecor.h
 *
 * Created: 1/22/2014 10:14:10 AM
 *  Author: user
 */ 


#ifndef CL_ALARMDETECOR_H_
#define CL_ALARMDETECOR_H_

#include "cl_types.h"
#include "cl_alarmdetector.h"

#define CL_ALARM_TRIGGERED 1
#define CL_ALARM_CLEARED 0
typedef enum
{
	CL_ALARM_NOSTATE,
	CL_ALARM_DETECTED,
	CL_ALARM_ACTIVE,
	CL_ALARM_MUTE,
	CL_ALARM_INACTIVE
}Cl_AlarmStateType;
typedef enum{
	LOWER,
	NORMAL,
	CRITICAL
}AlarmSeverityType;
typedef enum
{
	CL_ALARM_NOTYPE,
	CL_ALARM_ALARM,
	CL_ALARM_ALERT,
	CL_ALARM_HYBRID,
	CL_ALARM_MAXTYPE
	
}Cl_AlarmType;
typedef enum
{
	LOGIC_LOW,
	LOGIC_HIGH,
	ABOVE,
	BELOW,
	RANGE,
	COUNT,
	CHANGE,
	LOW_HIGH,
	HIGH_LOW,
	MAX_TRIGGER
	
	
}Cl_AlarmTriggerType;



typedef struct  
{
	int16_t cond_low_threshold;
	int16_t cond_high_threshold;
	int16_t cond_dac_high_threshold;
	int16_t cond_dac_low_threshold;
	float apt_high_threshold;
	float apt_low_threshold;
	float vpt_high_threshold;
	float vpt_low_threshold;
	float ps1_high_threshold;
	float ps1_low_threshold;
	float ps2_high_threshold;
	float ps2_low_threshold;
	float ps3_high_threshold;
	float ps3_low_threshold;
	float tmp_high_threshold;
	float tmp_low_threshold;
	float temp1_high_threshold;
	float temp1_low_threshold;
	float temp2_high_threshold;
	float temp2_low_threshold;
	float temp3_high_threshold;
	float temp3_low_threshold;
	float heater_high_temp_threshold;
	int16_t hp_high_speed_threshold;
	int16_t hp_low_speed_threshold;
	int16_t bp_high_speed_threshold;
	int16_t bp_low_speed_threshold;
	int16_t uf_high_speed_threshold;
	int16_t uf_low_speed_threshold;
	int16_t flow_low_threshold;
	int16_t flow_high_threshold;
	int16_t ls_toggle_high_threshold;
	int16_t ls_toggle_low_threshold;
	int16_t bc_toggle_high_threshold;
	int16_t bc_toggle_low_threshold;
	

}Cl_AlarmThresholdType;

typedef enum
{ 
	SENSOR_NO_DEVICE, //0x00
	SENSOR_BLOODDOOR_STATUS,//0x01
	SENSOR_BYPASSDOOR_STATUS,//0x02
	SENSOR_HOLDER1STATUS, // 0x03
	SENSOR_HOLDER2STATUS,// 0x04
	SENSOR_LEVELSWITCH,//0x05
	SENSOR_COND_WIEN_STATUS,
	SENSOR_COND_STATUS,//0x6
	SENSOR_COND_DAC,//0x7
	SENSOR_ABDSTATUS,//0x08
	SENSOR_BDSTATUS,//0x09
	SENSOR_APTSTATUS,//0x0A
	SENSOR_VPTSTATUS,//0x0B
	SENSOR_BLDSTATUS,//0x0C
	SENSOR_PS1STATUS,//0x0D
	SENSOR_PS2STATUS,//0x0E
	SENSOR_PS3STATUS,//0x0F
	SENSOR_PS4STATUS,//0x10
	SENSOR_TEMP1STATUS,//0x11
	SENSOR_TEMP2STATUS,//0x12
	SENSOR_TEMP3STATUS,//0x13
	SENSOR_FPCURRENTSTATUS,//0x14
	SENSOR_DGPstatus,//0x15
	SENSOR_HP_START,//0x16
	SENSOR_HP_END,//0x17
	SENSOR_FLOW_SWITCH,//0x18
	
	SENSOR_UFP_FB,//0x1A
	
	SENSOR_HP_FB,//0x1B
	SENSOR_BP_FB,//ox1C
	SENSOR_BP_INC_M,
	SENSOR_BP_DEC_M,
	SENSOR_BP_ON_OFF_M,
	SENSOR_ACID_INLET,
	SENSOR_BICARB_INLET,
	SENSOR_ACID_COND,
	SENSOR_BICARB_COND,
	SENSOR_POWER_FAILURE,
	SENSOR_VC_F_B,
	SENSOR_ACID_F_B,
	SENSOR_BICARB_F_B,
	SENSOR_MAX_INPUT	//0x1D
}Cl_SensorDeviceIdType;

/*
typedef enum
{ 
	ALARM_NO_ALARM,//0x00
	BLOODDOOR_STATUS_OPEN,//0x01
	BLOODDOOR_STATUS_CLOSED,
	BYPASSDOOR_STATUS_OPEN,//0x02
	BYPASSDOOR_STATUS_CLOSED,
	HOLDER1STATUS_OPEN, // 0x3
	HOLDER1STATUS_CLOSED,
	HOLDER2STATUS_OPEN,// 0x04
	HOLDER2STATUS_CLOSED,//0x05
	LEVELSWITCH_OFF_TO_ON,
	LEVELSWITCH_ON_TO_OFF,//0x6
	COND_STATUS_LOW,//0x7
	COND_STATUS_HIGH,//0x8
	COND_DAC_OPEN,//0x9
	COND_DAC_RO,//0xA
	COND_DAC_HIGH,//0xB
	ABDSTATUS_ON,//0x0D
	BDSTATUS_ON,//0x0E
	BDSTATUS_OFF,//0x0E
	APTSTATUS_HIGH,//0x0F
	APTSTATUS_LOW,
	VPTSTATUS_HIGH,//0x10
	VPTSTATUS_LOW,
	BLDSTATUS_ON,//0x11
	PS1STATUS_HIGH,//0x12
	PS1STATUS_LOW,
	PS2STATUS_HIGH,//0x13
	PS2STATUS_LOW,
	PS3STATUS_HIGH,
	PS3STATUS_LOW,//0x14
	PS4STATUS,//0x15
	TEMP1STATUS_HIGH,//0x16
	TEMP1STATUS_LOW,
	SENSOR_TEMP2STATUS,//0x17
	TEMP2STATUS_LOW,
	SENSOR_TEMP3STATUS,//0x18
	TEMP3STATUS_LOW,
	FPCURRENTSTATUS,//0x19
	DGPstatus,//0x1A
	UF_ROTATION_MARKER,//0x1B
	FLOWSTATUS_FLOWON,//0x1C
	FLOWSTATUS_FLOWOFF,//0x1D
	HP_START,//0x1E
	HP_END,//0x1F
	HP_ROTATION_MARKER,//0x20
	BP_ROTATION_MARKER, //0x21
	FLOW_NO_FLOW,//0x22
	FLOW_LOW_FLOWRATE,//ox23
	FLOW_HIGH_FLOWRATE,//0x24
	LEVEL_SWITCH_STOPPED,//0x25
	LEVEL_SWITCH_LOW_TOGGLERATE,//0x26
	LEVEL_SWITCH_HIGH_TOGGLERATE,
	HEATER_UNSTABLE,
	HEATER_HIGH_TEMP,
	HEATER_FAILURE,
	UFP_OVERRUN,
	UFP_UNDERRUN,
	HP_OVERRUN,
	HP_UNDERRUN,
	BP_OVERRUN,
	BP_UNDERRUN,
	CONSOLE_SYNC_LOST,
	BC_OVERRUN,
	BC_UNDERRUN,
	BC_FAILED,
	DE_CHAMBER,
	SYSTEM_NOT_READY,
	POWER_FAILURE,
	WATCHDOG_TIMER,
	ALARM_MAX_ID	//0x21
}Cl_NewAlarmIdType;

*/
typedef enum
{
	_NO_ALARM, //0
	BLOODDOOR_STATUS_OPEN,//1
	BYPASSDOOR_STATUS_OPEN,//2
	HOLDER1STATUS_OPEN, // 3
	HOLDER2STATUS_OPEN,// 4
	HOLDER1STATUS_CLOSED, // 5
	HOLDER2STATUS_CLOSED,// 6
	COND_STATUS_LOW,//7
	COND_STATUS_HIGH,//8
	COND_DAC_OPEN,//9
	COND_DAC_RO,//10 //A
	COND_DAC_HIGH,//11 //B
	FLOW_NO_FLOW,//12 //C
	FLOW_LOW_FLOWRATE,//13 //D
	FLOW_HIGH_FLOWRATE,//14  //E
	TEMP1_HIGH_THRESHOLD,//15 //F
	TEMP1_LOW_THRESHOLD, //16//10
	TEMP2_HIGH_THRESHOLD,//17 //11
	TEMP2_LOW_THRESHOLD, //18 //12
	TEMP3_HIGH_THRESHOLD,//19 //13
	TEMP3_LOW_THRESHOLD,//20 //14
	PS1_HIGH_THRESHOLD,//21 //15
	PS1_LOW_THRESHOLD,//22 //16
	PS2_HIGH_THRESHOLD,//23 //17
	PS2_LOW_THRESHOLD,//24 //18
	UF_ALARM_FOR_RINSE , //25 //19
	BC_ALARM, //26 //1A
	DE_CHAMBER_LOW, //27 //1B
	SYSTEM_NOT_READY,//28 //1C
	POWER_FAILURE,//29 //1D
	POWER_SUPPLY_OOR , //30 //1E
	WATCHDOG_TIMER , //31 //1F
	ABD_EVENT,//0x06
	BD_EVENT,//0x07
	BLD_EVENT,//0x0A
	APTSTATUS_LOW,//0x08,
	APTSTATUS_HIGH,//0x08
	VPTSTATUS_LOW,//0x09
	VPTSTATUS_HIGH,//0x09
	PS3_HIGH_THRESHOLD,
	PS3_LOW_THRESHOLD,
	ACID_IN_OPEN,
	ACID_IN_CLOSED,
	BICARB_IN_OPEN,
	BICARB_IN_CLOSED,
 	LEVEL_SWITCH_LOW_TOGGLERATE,
 	LEVEL_SWITCH_HIGH_TOGGLERATE,
 	HEATER_UNSTABLE,
 	HEATER_HIGH_TEMP,
 	HEATER_FAILURE,
 	UFP_OVERRUN,
 	UFP_UNDERRUN,
 	HP_OVERRUN,
 	HP_UNDERRUN,
 	BP_OVERRUN,
 	BP_UNDERRUN,
 	CONSOLE_SYNC_LOST,
 	BC_OVERRUN,
 	BC_UNDERRUN,
 	BC_FAILED,
	FPCURRENTSTATUS,
	LEVELSWITCH_OFF_TO_ON,
	LEVELSWITCH_ON_TO_OFF,
	BP_STOPPED,
	BLOOD_NOT_DETECTED,
	TMP_HIGH,
	TMP_LOW,
	_ALARM_MAX_ID	//0x21
}Cl_NewAlarmIdType;


typedef struct
{
	Cl_NewAlarmIdType cl_alarmID;
	Cl_AlarmTriggerType cl_triggertype;
	Cl_AlarmStateType cl_alarmstate;
	Cl_AlarmType cl_alarmType;
	float cl_upper;
	float cl_lower;
	Cl_Uint8Type  count_threshold;
	Cl_Uint8Type cl_detected_count;
	Cl_BoolType cl_is_enabled;
	Cl_BoolType cl_is_raised;
	
	
}Cl_AlarmStructType;




#endif /* CL_ALARMDETECOR_H_ */
