BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_RESUME:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	goto BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm 1, 10, 2
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement 1, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end


BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant_2
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant_1:
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant_2:
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant_1


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement 1, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return


BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_2
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_1:
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_5
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_4:
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	compare VAR_FACING, DIR_SOUTH
	goto_if_eq BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_8
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_7:
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_2:
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_1

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_5:
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_4

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_8:
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner_7


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end


BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end


BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end


BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner::
	.string "Please find a partner from out of\nthe TRAINERS gathered here.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner::
	.string "{PLAYER}, you have not found a partner\nfor your tag team.\pWould you like to quit looking and\nreturn to the reception counter?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2::
	.string "Then, please find a partner from\nthe TRAINERS gathered here.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Thank you for choosing a partner.\pI will now show you to your\nMULTI BATTLE ROOM.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "I'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\nYou can call me {STR_VAR_3}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "On {STR_VAR_1}'s advice, I brought\none {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pPlease, let me join you as a tag team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Thank you!\nI'll go register right now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "I really wanted to form a tag team\nwith you, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "I am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\nMy name is {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "I got advice from {STR_VAR_1} and chose\none {STR_VAR_3} with {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pPlease, let's form a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Thank you very much!\nI'll be done with registration quickly!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, I was hoping that I could\npartner up with you…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Um, my name's {STR_VAR_3}, and I'm\n{STR_VAR_1}'s no. {STR_VAR_2} apprentice.\pSnivel…\pI'm sorry!\nThis tension is making me cry…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} advised me, so I have\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pSnivel…\nPlease, please team up with me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh, really? You will?\nAwesome! Wicked! Awoooh!\pOh… I'm sorry…\nI'm so happy, I'm crying…\pI'll go register right away.\nPlease don't go away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, b-but…\nSob… Waaaaah!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Hi, there! I'm {STR_VAR_3}!\nI'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} recommended my crew.\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1},\nthat's what I have! Cool, huh?\pSo come on!\nLet's form a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Yay! Great!\nOkay, I'll go register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Aww, why?\nI wanted to team up, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "I'm {STR_VAR_3}, the no. {STR_VAR_2} apprentice\nof the famous {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "I looked to {STR_VAR_3} for advice.\nOne {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1},\nthat's my pair.\pPlease, will you join me in\na tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Thank you!\nI'll register right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, I had been hoping to join\nyou in a tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Um… I'm sincerely happy that you\nwould take the time to talk to me.\pI'm {STR_VAR_3}.\nI'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} gave me advice.\nI'm very grateful for it.\pI have a team of one {STR_VAR_2}\nwith {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\nI know I'm asking a lot…\pI don't think you'll be willing to,\nbut may I join you as a partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Really? I can't believe it!\nI can't believe you'll let me join you!\lI… I won't let you down!\pUm… If it's really okay, I'll go register\nright this instant!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\nI didn't think I was good enough…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Hi, I'm {STR_VAR_3}.\nI'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} told me that it would be\ngood to make this team:\lone {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "and one {STR_VAR_2} that knows how\nto use {STR_VAR_1}.\pNot bad, huh?\nWant me to team up with you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "Okay, glad to join you!\nI hope you won't mess things up for me!\lI'll do my registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Huh? Why did you turn me down?\nYou're no judge of character!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "I'm {STR_VAR_3} and I'm a TRIATHLETE.\nI'm busy every day what with jogging,\ltraining, and rapping.\pI also happen to be {STR_VAR_1}'s\nno. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "This is what {STR_VAR_3} recommended.\nOne {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "and one {STR_VAR_1}-using\n{STR_VAR_2}.\pI put a lot of effort into raising\nthem, even though I'm busy.\pLet's form a tag team\nand give it a go!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Thanks, that's the spirit!\nHang tight while I go register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "I took time from my busy schedule\nto be here! Give me a break!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Hi!\nHow's it going?\pI'm {STR_VAR_3}, {STR_VAR_1}'s\nno. {STR_VAR_2} apprentice. Glad to meet you!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Listen, listen! You have to hear about\nthe POKéMON {STR_VAR_3} recommended.\lOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\nOf course I raised them superbly!\pSo, want to team up?\nI'm sure it'll be a great combo!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Yay, I think this will be fun!\nI'll go register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, you're mean!\nI come recommended, you know.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Please let me introduce myself.\nI am {STR_VAR_3}.\pI serve as {STR_VAR_1}'s\nno. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "I sought the sage advice of\n{STR_VAR_3} and raised my team\lof one {STR_VAR_2} with {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1}.\pPlease agree to a tag team with me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… I'm delighted!\nI promise to give you my best!\pOf course I will register us!\nPlease wait!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "I had been hoping to join you,\n{PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Eek! You spoke to me!\nI… I'm overjoyed!\pI'm {STR_VAR_3}! I'm {STR_VAR_1}'s\nno. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "On {STR_VAR_3}'s advice, I trained\none {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "and one {STR_VAR_1}-using\n{STR_VAR_2}.\pPlease, can you grant me my wish?\nI want to be your tag-team partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Eek! I… I feel giddy!\nThank you so much!\lI'll go register us right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah! Don't you feel any pity?\nBut that makes you cooler…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Yeehaw! I'm {STR_VAR_1}'s\nno. {STR_VAR_2} apprentice!\p{STR_VAR_3}'s my name, hello, hello!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "My mentor {STR_VAR_3} recommended\none {STR_VAR_1}-master {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "and one {STR_VAR_1}-master\n{STR_VAR_2}.\pGood stuff, huh?\nYou'll partner with me, won't you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "Okay, excellent!\nI'll get the registration done quickly!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah!\nYou're a calculating one, {PLAYER}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hey! There's big trouble! This is\nthe BATTLE TOWER's last day!\p… … … … … …\nI'm only joking!\pPeople call me {STR_VAR_3} and I do, too!\nI'm {STR_VAR_1}'s 1,000th apprentice!\lActually, I'm no. {STR_VAR_2}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} gave me some advice.\n{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} with {STR_VAR_1}.\nI've got ten of each kind!\lActually, just one of each!\pHow about it?\nWant to try tag battles with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Yippee!\nI'll give you a POKéMON as my thanks!\pJust joking! But I will really go do\nthe registration, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, that's so cold! I'll have to wreck\nthe BATTLE TOWER for that!\pOf course I won't!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Hey, there, I'm rockin' and a-rollin'!\nPOKéMON, I be controllin'!\pI'm {STR_VAR_3} the rappin' SAILOR.\nDon't be mistakin' me for no wailer!\pI'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice.\nMe, you shouldn't be quick to dismiss!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "With the advice of {STR_VAR_3} I did\nabide, put together my team of pride!\lOne {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "and one {STR_VAR_1}-using\n{STR_VAR_2}!\pOur meeting we should commemorate,\nwith a tag-team victory to celebrate!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hey, hey, I like your style!\nOur registration, I will go file!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, hey, {PLAYER}, now that's cold!\nIf I may be so bold!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Yippee-yahoo!\nOh, don't run! I was just having fun!\pHowdy! I'm {STR_VAR_3}!\nI'm {STR_VAR_1}'s no. {STR_VAR_2} apprentice!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} told me what to do.\nSo one {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "and one {STR_VAR_1}-using\n{STR_VAR_2}, I did choose.\pSo, what do you say?\nCome on, make my day!\pPlease, I'm begging you!\nLet me join you, don't leave me blue!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Yeahah! Luck is with me!\nIt sure makes me happy!\pBefore we go join the fray,\nI'll go register right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "You're turning me down?\n{PLAYER}, you're making me frown!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Cough!\pOh, sorry, I have a cold.\nMy POKéMON are fine, though.\pMy name's {STR_VAR_3}, {STR_VAR_1}'s\nno. {STR_VAR_2} apprentice. Cough!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "I took {STR_VAR_3}'s advice to heart\nand put together my team of\lone {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pI trained them every day,\neven in wind and rain.\pThat's why I have this cold,\nI think.\pThat's what I'm about.\nWant to be my tag partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Thanks, I appreciate this!\nCough, cough!\lHang on while I go register.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, you won't?\n{PLAYER}, I think we'd make a good pair.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, hello!\nThis is nerve-racking.\pI'm {STR_VAR_3}.\nI'm the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} said this team'll be good--\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pI'm feeling self-conscious about this,\nbut will you let me join you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, gee, thank you!\nI feel bashful, but I'll do my best!\pI'll go get the registration done.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, please don't say no!\nI feel self-conscious enough already…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "I am {STR_VAR_3}, and that's no lie.\nI am {STR_VAR_1}'s no. {STR_VAR_2} apprentice.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} recommended my team.\pSince the advice sounded sincere,\nI decided to bring with me\lmy {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "my {STR_VAR_1}-using {STR_VAR_2}.\pIf possible, I would like you to accept\nme as your tag-team partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "You really will accept me?\nIt would be too terrible otherwise.\pBut since you've agreed, this is fine.\nI shall go register the both of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm? Now why would you refuse?\nIs this your idea of a joke?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "I'm {STR_VAR_1}, and I'm a LASS!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "What I have are one {STR_VAR_2}\nthat uses {STR_VAR_1} and one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{STR_VAR_2} that uses {STR_VAR_1}.\nThose are what I have with me.\pWill you be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Thank you!\nI'll go do the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "You don't want to be my partner?\nYou'll regret it later!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Hello!\pI'm YOUNGSTER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Want to know what I have?\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pYou'll be my tag-team partner,\nwon't you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Yay!\nI'll go and register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Aww! If you'd form a tag team with\nmy POKéMON, we'd be unstoppable!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Yahoo!\nI'm HIKER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Know what I have with me?\nMy {STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "my {STR_VAR_1}-using {STR_VAR_2}!\pSounds good, eh?\nWant to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Yahoo!\nI'll go do the registering, then.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "I would've liked to battle with you\nat my side.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Hello!\nI'm {STR_VAR_1}, and I'm a BEAUTY!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Do you know what I've been raising?\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pWhat do you think?\nWant to make a tag team together?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Wonderful!\nI'll get the registration done now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "How disappointing!\pWe two together--we would've been\nthe best!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Yo!\pYou know who I am?\nI'm {STR_VAR_1} the FISHERMAN!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "I've got with me a team of one\n{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\pSo, how about it?\nWill you battle at my side?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Good, good!\nLeave it up to me!\pI'll go and register us now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "We matched up perfectly, too…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Glad to make your acquaintance.\nI am {STR_VAR_1}, a LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "I am accompanied by a team of\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pI hope I meet your approval.\nFor I wish to have you as my partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "I thank you sincerely.\nI shall handle the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "I'm sure that you will regret not\nhaving me as your partner.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "I'm TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "What I have…\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\nThat's my pair!\pPlease?\nWill you form a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Gee, thanks!\nI'll go register at the counter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "We two together, we would've been\ntough for certain!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Hiya!\nI'm BUG CATCHER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Check out what I have!\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pSo, listen!\nDo you want to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Gotcha!\pI'll go do the registration stuff\nat the counter.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Aww, my POKéMON are awesome.\nI hope you won't regret this!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Good day!\nI'm SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "What I've been raising are one\n{STR_VAR_2} that uses {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "and one {STR_VAR_2} that uses\n{STR_VAR_1}.\pNot too bad, don't you think?\nWould you care to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Thank you very much!\nI'll get done with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "That's too bad…\pI was hoping that I could learn\nfrom you as your partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Yo! Let me tell you who I am!\nI'm RICH BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Guess what I got!\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pI'm willing to offer you the chance\nto be in a tag team with me.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Smart move!\pI'll finish up the registration\nprocess quick!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "You'd turn me of all people down?\nYou'll regret that decision for sure!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah!\nI am BLACK BELT {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "As my companions, I have\none {STR_VAR_2} using {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "and one {STR_VAR_2} using\n{STR_VAR_1}.\pPlease, grant me my wish!\nAllow me to be your tag partner!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah!\nI will go register forthwith!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "I see… I hope for an opportunity\nthe next time we meet…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Hi, there!\nI'm {STR_VAR_1}, and I'm a TUBER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "I'll tell you what I have.\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\nMay I please be on your tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Thank you!\nI'll go register us now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "If we'd become partners, we could\nhave been so strong!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Greetings…\nI am HEX MANIAC {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "I bear with me one {STR_VAR_1}-using\n{STR_VAR_2} together with one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1}-using {STR_VAR_2}…\pI beseech you…\nJoin me in a tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "I thank you…\nI shall register us…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "I so longed to join you…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "How do you do? I'm {STR_VAR_1},\nand I'm a POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "I'm raising a couple good ones!\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pHow about it?\nFeel like making a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Thank you kindly!\pI'll go take care of the registration\nstuff, so you wait right here!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "I was looking forward to being\nyour partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Well, hello!\nI'm TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Want to know what I run with?\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pWell?\nWant to be in a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Good going!\pI'll be quick and get the registration\nall done!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "You and me, we would've been tops.\nIt's too bad…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Hey, there! My name's {STR_VAR_1}!\nI'm a TRIATHLETE!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "I go on runs with my durable team--\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pNot too shabby, huh?\nWe should be in a tag team together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "All right!\nI'll go register in a flash!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "I really wanted to battle as your\ntag-team partner…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "I'm BATTLE GIRL {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "I've been toughening up one\n{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}!\pDo you like that combo?\nHow about you and me join up?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Why, thanks!\pI'll get the registration done\nright now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "With you, I thought we could form\nthe ultimate tag team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "I'm TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "I've been running with one {STR_VAR_2}\nthat knows how to use {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "and one {STR_VAR_2} with {STR_VAR_1}!\pWe could be in a tag team.\nWouldn't that be great?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Thank you!\pI'll go register us, and that's\nright now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Aww, that's too bad. We would've been\nthe toughest tag team around!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Me?\nI'm TUBER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "What do I have with me?\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pHey?\nYou'll team up with me, right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "Okay!\pI'll go register!\nLet's be excellent together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "My POKéMON are tough for sure…\nIt's too bad you don't want to team up.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yay-hey!\nCall me GUITARIST {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Check out my entourage!\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pYay-hey! Pretty wild, huh?\nWe'll have to do a duet in a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Yay-hey! Right on!\nI'll do that registration stuff now!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "My POKéMON rock hard!\nYou'll be sorry, I tell you!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Pleased to meet you.\nI am {STR_VAR_1}, a GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "I am accompanied by my trusted\n{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\pMay I ask you to join me in a tag-team\npartnership arrangement?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, I thank you for your trust.\nI shall be done with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "That is most unfortunate…\pI shall look forward to the next\nopportunity…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Hello, I'm {STR_VAR_1},\nand I'm a POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "I have with me now one {STR_VAR_2}\nthat knows the move {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pDo you like what you see?\nWhy don't you be my tag partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Thank you!\nI'll look after the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "My POKéMON are top grade…\nIt's too bad you can't appreciate that.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm!\nI am {STR_VAR_1}, and an EXPERT am I!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "The POKéMON that I've toughened up are\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pWhat say you to a tag team with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm!\nI shall register us right away!\lLet us both do our best!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "I will hope that your choice is\nindeed correct…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Hello, hello.\nI'm {STR_VAR_1}, and I'm an EXPERT.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "I've raised my POKéMON thoroughly.\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\nthey're what I have.\pWouldn't you like to team up with me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Good, good.\nI'll see to the registration right away.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Perhaps we can form a team the next\ntime we meet.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "I'm DRAGON TAMER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "The team I've been toughening up is\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pHow about it?\nWant to be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "Okay, I'll give it my best!\nI'll go register now, all right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "You're not going to find many tougher\npartners than me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "I'm BIRD KEEPER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "What POKéMON do I have?\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pDon't you think we'd make a decent\ntag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Great, thanks!\nI'll look after the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "My POKéMON and I are strong.\nWhat a letdown.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "I'm NINJA BOY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "My POKéMON team consists of one\n{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pLet's be in a tag team together!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Yay!\nLet me go register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "You'll regret not having my tough\nPOKéMON on your side!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Hello!\nI'm PARASOL LADY {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "Escorting me now are my {STR_VAR_2}\nthat uses {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "one {STR_VAR_2} that uses\n{STR_VAR_1}.\pAren't they nice?\nCare to join us in a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Thanks a bunch!\pI'll go register at the counter.\nLet's not disappoint each other!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "My POKéMON are tremendously strong.\nHow disappointing…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Hello.\nI'm {STR_VAR_1}, and I'm a BUG MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "I have found my POKéMON, yes.\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\nthey are what I found.\pCould I interest you in forming\na tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "Okay!\nUnderstood!\pI won't be long with the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "With the POKéMON I found, we wouldn't\nhave lost…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ahoy, there!\nI'm SAILOR {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Let me show you my pride and joy!\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pOf course you're not going to turn\nme down. We will team up, right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "I didn't expect any less!\nI'll go register now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "We would've stormed through\nthe opposition! Too bad!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Hi, I'm {STR_VAR_1}.\nI'm a COLLECTOR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "The jewels in my collection are\nmy {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pSwell, huh?\nWe should be in a team together.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, yeah!\pWell, let's not waste any time.\nI'll go register the two of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Well, that's upsetting.\nYou don't appreciate my POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Howdy, I'm {STR_VAR_1}.\nI'm a POKéMON RANGER.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "Keeping me company are one\n{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pDon't you think we'd make an impressive\ntag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "That's super!\nI'll deal with the registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "Next time, choose my POKéMON,\nwill you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "My name's {STR_VAR_1}.\nI'm a POKéMON RANGER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Let me tell you about my team. I have\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pHow would you like to form a tag team\nwith my little posse?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "We'll be at our best!\nI'll get the registration done quick!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "I hope you'll choose my POKéMON\nnext time.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Pleased to meet you. I'm {STR_VAR_1}.\nI consider myself an AROMA LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "I travel with one {STR_VAR_2}\nthat uses {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "one {STR_VAR_2} that uses\n{STR_VAR_1}.\pI hope they strike your fancy.\nWould you care to be my partner?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "I'm honored by your acceptance.\nI will go register right this instant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "It would be wonderful if we could form\na tag team the next time we meet.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Want to know who I am?\nI'm {STR_VAR_1}, the RUIN MANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "The POKéMON that I have with me are\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pIntriguing, eh?\nHow about you and I partner up?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "That's a sound decision!\nI'll go do the registration paperwork.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm…\nI think my POKéMON are tough…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "I'm COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "The POKéMON I have right now are one\n{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\nCool, huh?\pDon't you think it'd be pretty cool\nif we made a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Cool!\nI'll go do the registration in a flash!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "I thought that we'd make just\nthe greatest team ever.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "I'm COOLTRAINER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "The team I've been raising has one\n{STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pDoes that sound okay?\nHow about we become tag partners?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Sounds A-OK!\nI'd better do the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "I was thinking how we would be\none tough team…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Heyo!\nI'm {STR_VAR_1}, the POKéMANIAC!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "What does a guy like me have?\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1},\nthat's what!\pLet's do it!\nWe'll stomp around as a tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Good call!\nI'll register the both of us!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "My POKéMON are brutal!\nIt's not my fault if you regret this!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Yo, there!\nI'm KINDLER {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "You know what my training cooked up?\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pWell, what do you say?\nWant to form a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "All right!\nI'll get on with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Promise you'll partner up with me\nthe next time we run into each other.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "I'm {STR_VAR_1}, and I'm a CAMPER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "I've been raising one {STR_VAR_1}-\nusing {STR_VAR_2} and one$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{STR_VAR_1}-using {STR_VAR_2}.\pDo you think it'd be fun to team up?\nI bet it would be!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Yeah!\nOff I go to register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "Next time, okay?\nI want to be on your team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Hello!\nI'm {STR_VAR_1}, and I'm a PICNICKER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "The POKéMON I've been taking are\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pAre you interested in joining me\non a tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Why, thank you!\nI will do the registration now.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "It would be nice if I could join you\nsome other time.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "I'm PSYCHIC {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "The twosome I've been raising are\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pWould you like to form a tag team\nwith me?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Sure thing!\nI'll take care of the registration!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "If we meet again, that's when I'd like\nto team up with you.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "I'm {STR_VAR_1}.\nI'm a PSYCHIC.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}--\nthey're my disciples.\pDoesn't the idea of forming a tag-team\npartnership intrigue you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Thank you.\nI'll go deal with the registration.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "I hope there will be another chance\nto forge an alliance.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "I'm SCHOOL KID {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "and one {STR_VAR_1}-using\n{STR_VAR_2} are my POKéMON pair.\pMay I please be your partner on\na tag team?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, thank you!\nI'll register at the counter right away!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "Please?\nMay I join you the next time?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Hiya! The name's {STR_VAR_1}!\nI'm a POKéMON BREEDER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "The POKéMON I've raised are one\n{STR_VAR_1}-using {STR_VAR_2} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "one {STR_VAR_1}-using {STR_VAR_2}.\pSound interesting?\nHow about we form a tag team, then?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "All righty!\nYou leave the registration to me!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "You have to team up with me next time,\nall right?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "I'm {STR_VAR_1}, and I'm proud to say\nthat I am a POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "The darling POKéMON I've raised are\none {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}.\pAren't they just the cutest?\nWe ought to make a team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Thank you, dear!\nI'll be on my way to register!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "My darling POKéMON are the best,\nI'll have you know. How annoying!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Hi, I'm SWIMMER {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "One {STR_VAR_1}-using {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "and one {STR_VAR_1}-using\n{STR_VAR_2} are what I've trained.\pYou and me, let's make a tag team.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "That's cool!\nI'll register the two of us.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "If we meet again, you owe me\na tag team!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "What's happening?\nI'm {STR_VAR_1}, and I'm a TRIATHLETE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "I got a couple decent POKéMON.\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pIt'd be neat if we made a tag team\ntogether, so how about it?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Right on!\nYou wait while I register, okay?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "I expect you'll let me join you\nnext time, how's that?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "I'm the TRIATHLETE {STR_VAR_1}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "One {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "another {STR_VAR_2} that knows how\nto use {STR_VAR_1}. That's my pair.\pWhat do you think?\nWe'd make a good team, I'd say.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "I like that answer!\nI'll get done with registration fast!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "You'll give me another chance to form\na partnership, won't you?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Hi, there! Hello!\nI'm {STR_VAR_1}, and I'm a SWIMMER!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Check out what I've been raising!\nOne {STR_VAR_2} with {STR_VAR_1} and$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "one {STR_VAR_2} with {STR_VAR_1}!\pSweet, huh?\nIt'd be sweet to form a team, too!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Much obliged!\nI'll get this registration thing done!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "If we meet again, you have to team up\nwith me. You'll do that, right?$"
