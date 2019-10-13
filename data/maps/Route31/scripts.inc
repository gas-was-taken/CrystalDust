Route31_MapScripts:: @ 81EC38E
	@map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	@map_script MAP_SCRIPT_ON_LOAD, Route31_MapScript1_1EC3A4
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route31_MapScript2_FrameTable
	.byte 0

Route31_MapScript2_FrameTable:
	map_script_2 VAR_ROUTE31_STATE, 0, Route31_EventScript_MomCall
	.2byte 0

Route31_EventScript_MomCall:
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	pokegearcall PhoneScript_Mom, 0
	waitstate
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	addvar VAR_ROUTE31_STATE, 1
	releaseall
	end

Route31_OnTransition: @ 81EC399
	call Common_EventScript_SetupRivalGender
	call Route31_EventScript_2720AD
	end

Route31_MapScript1_1EC3A4: @ 81EC3A4
	call_if_set FLAG_SYS_GAME_CLEAR, Route31_EventScript_1EC3AE
	end

Route31_EventScript_1EC3AE:: @ 81EC3AE
	setmetatile 45, 5, 159, 1
	setmetatile 45, 6, 167, 0
	return

Route31_EventScript_1EC3C1:: @ 81EC3C1
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route31_EventScript_1EC3DA
	compare VAR_RESULT, FEMALE
	goto_if_eq Route31_EventScript_1EC434
	end

Route31_EventScript_1EC3DA:: @ 81EC3DA
	msgbox Route31_Text_1EC7A6, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RIVALENC, 1
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox Route31_Text_1EC7DE, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route31_EventScript_1EC48E
	case 1, Route31_EventScript_1EC49E
	case 2, Route31_EventScript_1EC4AE
	end

Route31_EventScript_1EC434:: @ 81EC434
	msgbox Route31_Text_1EC989, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RIVALEXIT, 1
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox Route31_Text_1EC9CE, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route31_EventScript_1EC4BE
	case 1, Route31_EventScript_1EC4CE
	case 2, Route31_EventScript_1EC4DE
	end

Route31_EventScript_1EC48E:: @ 81EC48E
	trainerbattle_no_intro TRAINER_MAY_4, Route31_Text_1EC881
	goto Route31_EventScript_1EC4EE
	end

Route31_EventScript_1EC49E:: @ 81EC49E
	trainerbattle_no_intro TRAINER_MAY_7, Route31_Text_1EC881
	goto Route31_EventScript_1EC4EE
	end

Route31_EventScript_1EC4AE:: @ 81EC4AE
	trainerbattle_no_intro TRAINER_MAY_1, Route31_Text_1EC881
	goto Route31_EventScript_1EC4EE
	end

Route31_EventScript_1EC4BE:: @ 81EC4BE
	trainerbattle_no_intro TRAINER_BRENDAN_4, Route31_Text_1ECA59
	goto Route31_EventScript_1EC4FC
	end

Route31_EventScript_1EC4CE:: @ 81EC4CE
	trainerbattle_no_intro TRAINER_BRENDAN_7, Route31_Text_1ECA59
	goto Route31_EventScript_1EC4FC
	end

Route31_EventScript_1EC4DE:: @ 81EC4DE
	trainerbattle_no_intro TRAINER_RIVAL_2, Route31_Text_1ECA59
	goto Route31_EventScript_1EC4FC
	end

Route31_EventScript_1EC4EE:: @ 81EC4EE
	msgbox Route31_Text_1EC8AE, MSGBOX_DEFAULT
	goto Route31_EventScript_1EC50A
	end

Route31_EventScript_1EC4FC:: @ 81EC4FC
	msgbox Route31_Text_1ECA79, MSGBOX_DEFAULT
	goto Route31_EventScript_1EC50A
	end

Route31_EventScript_1EC50A:: @ 81EC50A
	closemessage
	switch VAR_FACING
	case 1, Route31_EventScript_1EC585
	case 2, Route31_EventScript_1EC53D
	case 3, Route31_EventScript_1EC561
	case 4, Route31_EventScript_1EC561
	end

Route31_EventScript_1EC53D:: @ 81EC53D
	applymovement EVENT_OBJ_ID_PLAYER, Route31_Movement_1EC5C8
	applymovement 2, Route31_Movement_1EC5BE
	waitmovement 0
	playse SE_DANSA
	applymovement 2, Route31_Movement_1EC5C1
	waitmovement 0
	goto Route31_EventScript_1EC5A2
	end

Route31_EventScript_1EC561:: @ 81EC561
	applymovement EVENT_OBJ_ID_PLAYER, Route31_Movement_1EC5D6
	applymovement 2, Route31_Movement_1EC5CE
	waitmovement 0
	playse SE_DANSA
	applymovement 2, Route31_Movement_1EC5D0
	waitmovement 0
	goto Route31_EventScript_1EC5A2
	end

Route31_EventScript_1EC585:: @ 81EC585
	applymovement 2, Route31_Movement_1EC5CE
	waitmovement 0
	playse SE_DANSA
	applymovement 2, Route31_Movement_1EC5D0
	waitmovement 0
	goto Route31_EventScript_1EC5A2
	end

Route31_EventScript_1EC5A2:: @ 81EC5A2
	removeobject 2
	setvar VAR_ELM_LAB_STATE, 4
	clearflag FLAG_HIDE_NEW_BARK_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE31
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_CHERRYGROVE_CITY_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route31_Movement_1EC5BE: @ 81EC5BE
	walk_left
	walk_down
	step_end

Route31_Movement_1EC5C1: @ 81EC5C1
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route31_Movement_1EC5C8: @ 81EC5C8
	delay_16
	delay_4
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

Route31_Movement_1EC5CE: @ 81EC5CE
	walk_down
	step_end

Route31_Movement_1EC5D0: @ 81EC5D0
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route31_Movement_1EC5D6: @ 81EC5D6
	delay_16
	walk_in_place_fastest_down
	step_end

Route31_EventScript_1EC5D9:: @ 81EC5D9
	msgbox Route31_Text_1ECB73, MSGBOX_NPC
	end

Route31_EventScript_1EC5E2:: @ 81EC5E2
	msgbox Route31_Text_1ECBB5, MSGBOX_NPC
	end

Route31_EventScript_1EC5EB:: @ 81EC5EB
	msgbox Route31_Text_1ECC1A, MSGBOX_SIGN
	end

Route31_EventScript_1EC5F4:: @ 81EC5F4
	trainerbattle_single TRAINER_DAISY, Route31_Text_29495A, Route31_Text_29498F
	msgbox Route31_Text_2949B4, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC60B:: @ 81EC60B
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route31_Text_2949F9, Route31_Text_294A3D, Route31_Text_294AAE, Route31_EventScript_1EC63A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route31_EventScript_1EC653
	msgbox Route31_Text_294A52, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC63A:: @ 81EC63A
	msgbox Route31_Text_294B8A, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route31_EventScript_1EC653:: @ 81EC653
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route31_Text_294C29, Route31_Text_294C6D, Route31_Text_294CEF
	msgbox Route31_Text_294C93, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC66E:: @ 81EC66E
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route31_Text_294AFD, Route31_Text_294B22, Route31_Text_294BD0, Route31_EventScript_1EC69D
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route31_EventScript_1EC6B6
	msgbox Route31_Text_294B40, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC69D:: @ 81EC69D
	msgbox Route31_Text_294B8A, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route31_EventScript_1EC6B6:: @ 81EC6B6
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route31_Text_294D3E, Route31_Text_294D63, Route31_Text_294DDB
	msgbox Route31_Text_294D89, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC6D1:: @ 81EC6D1
	trainerbattle_single TRAINER_ANDREW, Route31_Text_294E34, Route31_Text_294E92
	msgbox Route31_Text_294EBB, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC6E8:: @ 81EC6E8
	trainerbattle_single TRAINER_MIGUEL_1, Route31_Text_294EDF, Route31_Text_294F21, Route31_EventScript_1EC714
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route31_EventScript_1EC733
	msgbox Route31_Text_294F42, MSGBOX_DEFAULT
	release
	end

Route31_EventScript_1EC714:: @ 81EC714
	special sub_80B4808
	waitmovement 0
	msgbox Route31_Text_294F7E, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route31_EventScript_1EC733:: @ 81EC733
	trainerbattle_rematch TRAINER_MIGUEL_1, Route31_Text_294FC3, Route31_Text_295006
	msgbox Route31_Text_29501E, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC74A:: @ 81EC74A
	trainerbattle_single TRAINER_MARCOS, Route31_Text_295206, Route31_Text_29522B
	msgbox Route31_Text_295246, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC761:: @ 81EC761
	trainerbattle_single TRAINER_RHETT, Route31_Text_295199, Route31_Text_2951C6
	msgbox Route31_Text_2951DE, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC778:: @ 81EC778
	trainerbattle_single TRAINER_PETE, Route31_Text_295063, Route31_Text_295093
	msgbox Route31_Text_2950AA, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_1EC78F:: @ 81EC78F
	trainerbattle_single TRAINER_ISABELLE, Route31_Text_295116, Route31_Text_295146
	msgbox Route31_Text_29514D, MSGBOX_AUTOCLOSE
	end

Route31_Text_1EC7A6: @ 81EC7A6
	.string "MAY: Let's see… The POKéMON found\n"
	.string "on ROUTE 103 include…$"

Route31_Text_1EC7DE: @ 81EC7DE
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

Route31_Text_1EC881: @ 81EC881
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

Route31_Text_1EC8AE: @ 81EC8AE
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

Route31_Text_1EC989: @ 81EC989
	.string "BRENDAN: Okay, so it's this one and\n"
	.string "that one that live on ROUTE 103…$"

Route31_Text_1EC9CE: @ 81EC9CE
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

Route31_Text_1ECA59: @ 81ECA59
	.string "Huh, {PLAYER}, you're not too shabby.$"

Route31_Text_1ECA79: @ 81ECA79
	.string "BRENDAN: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

Route31_Text_1ECB73: @ 81ECB73
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

Route31_Text_1ECBB5: @ 81ECBB5
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route31_Text_1ECC1A: @ 81ECC1A
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"
