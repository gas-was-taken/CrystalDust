Route29_MapScripts:: @ 81EBCBA
	map_script 3, Route29_MapScript1_Type3
	map_script 2, Route29_MapScript2_Type2
	.byte 0

Route29_MapScript1_Type3: @ 81EBCC5
	call Route29_MapScript1_CheckForTuscany
	end

Route29_MapScript1_CheckForTuscany:
	goto_if_unset FLAG_BADGE01_GET, Route29_EventScript_HideTuscany
	gettime
	compare VAR_0x8003, DAY_TUESDAY
	goto_if_ne Route29_EventScript_HideTuscany
	clearflag FLAG_HIDE_ROUTE_29_TUSCANY
	return

Route29_EventScript_HideTuscany:
	setflag FLAG_HIDE_ROUTE_29_TUSCANY
	return

Route29_MapScript2_Type2:
	.2byte 0

Route29_EventScript_Youngster::
	msgbox Route29_Text_Youngster, MSGBOX_NPC
	end

Route29_EventScript_LedgeGirl::
	msgbox Route29_Text_LedgeGirl, MSGBOX_NPC
	end

Route29_EventScript_FatMan::
	msgbox Route29_Text_FatMan, MSGBOX_NPC
	end

Route29_EventScript_DirectionSign::
	msgbox Route29_Text_DirectionSign, MSGBOX_SIGN
	end

Route29_Text_Youngster:
	.string "Yo. How are your POKeMON?\p"
	.string "If they're weak and not ready for battle,\n"
	.string "keep out of the grass.$"

Route29_Text_LedgeGirl:
	.string "See those ledges?\n"
	.string "It's scary to jump off them.\p"
	.string "But you can go to NEW BARK without\n"
	.string "walking through the grass.$"

Route29_Text_FatMan:
	.string "I wanted to take a break, so I saved to\n"
	.string "record my progress.$"

Route29_Text_DirectionSign:
	.string "ROUTE 29\n"
	.string "CHERRYGROVE CITY - NEW BARK TOWN$"