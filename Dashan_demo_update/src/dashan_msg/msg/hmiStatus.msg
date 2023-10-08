#communication link state
uint8 commLinkState
#button state
uint8 buttonState
#battery info
uint8 batteryState  # 0:normal state; 1:charge state
uint8 batteryPercent  # left percent 5%-100%

#temperature
uint8 temperature
#humidity
uint8 humidity
#smog alert
uint8 smogAlert  #1:alert 	0:no smog
#push rod pos
uint8 pushRodPos
#emergent push button
uint8 emergentState
#define CMD_SAVE_INIT_PARA 1
#define CMD_SAVE_GOAL_PSTN 2 here send the pos_x pos_y
#define CMD_SEND_GOALS 3 
#define CMD_SEND_CURR_PSTN 4
#define CMD_SAVE_POS 5
#define CMD_SEND_POS 6
#define CMD_SET_INIT_POS 7
#define CMD_VOICE 8
#define CMD_CLEAR_NAVIGOALS 9
uint8 zhishancmdshow
#position show
float32 pos_x
float32 pos_y