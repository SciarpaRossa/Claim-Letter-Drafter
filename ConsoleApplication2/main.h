#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#define COLUMN_A 0;
#define COLUMN_B 1;
#define COLUMN_C 2;
#define COLUMN_D 3;
#define COLUMN_E 4;
#define COLUMN_F 5;
#define COLUMN_G 6;
#define COLUMN_H 7;
using namespace std;


/////////////////////////////////////////////////////////////////////////////////////
//                   GLOBAL VARIABLES AND CONSTANT DEFINITIONS
/////////////////////////////////////////////////////////////////////////////////////


const int STR_SIZE = 2000;
const char FILE_DELIM = '\t';

// LINES correspond to Excel row numbers (start counting from 1)

const int OCC_LINE = 6;
const int OCC_COLUMN = COLUMN_C;
const int POLICY_LINE = 10;
const int POLICY_COLUMN = COLUMN_C;
const int CLASS_LINE = 11;
const int CLASS_COLUMN = COLUMN_C;
const int COVERAGE_LINE = 13;
const int COVERAGE_COLUMN = COLUMN_C;
const int BWP_LINE = 18;
const int TYPE_COLUMN = COLUMN_C;
//const int BWP_COLUMN = COLUMN_E;
const int BWP_COLUMN = COLUMN_H;
const int BENEFIT_AMT_LINE = 23;
const int BENEFIT_AMT_COLUMN = COLUMN_G;
const int DOD_LINE = 27;
const int DOD_COLUMN = COLUMN_C;
const int BENEFIT_FROM_LINE = 27;
const int BENEFIT_FROM_COLUMN = COLUMN_E;
const int CLDT_LINE = 31;
const int MBP_LINE = 33;
const int MBP_COLUMN = COLUMN_C;
const int MBP_DATE_COLUMN = COLUMN_F;
const int REASON_LINE = 34;
const int REASON_COLUMN = COLUMN_C;
const int OFFSET_LINE = 35;

// ILLNESS BWP LENGTHS

const int PROD_CS_3 = 48;
const int PROD_CS_5 = 6;


/////////////////////////////////////////////////////////////////////////////
//                         HTML FORMATTING DATA
/////////////////////////////////////////////////////////////////////////////



const string B("<b>");
const int B_NUM = 220;
const string SLASH_B("</b>");

const string I("<i>");
const int I_NUM = 227;
const string SLASH_I("</i>");

const string U("<u>");
const int U_NUM = 239;
const string SLASH_U("</u>");

/*
const string C("<center>");
const int C_NUM = 763;
const string SLASH_C("</center>");
*/

const string P("<p>");
const int P_NUM = 234;
const string SLASH_P("</p>");

const string BR("<br>");
const int BR_NUM = 334;

const string PCU("<p><center><u>");
const int PCU_NUM = 1236;
const string SLASH_PCU("</u></center></p>");

const string PCB("<p><center><b>");
const int PCB_NUM = 1217;
const string SLASH_PCB("</b></center></p>");


//////////////////////////////////////////////////////////////////////////////////
//                              POLICY VERBIAGE
//////////////////////////////////////////////////////////////////////////////////


// BENEFIT WAITING PERIOD

const string BWP_HEADER = "PAYMENT DETAILS";
const string BWP_INTRO = "Your Plan Document requires you to serve a Benefit Waiting period, during which no benefits are payable. This period is ";
const string DAYS = " days.";
const string DISABLED_ON = " You became disabled on ";
const string I_GENERAL = ", therefore your benefits are payable beginning on ";
const string H_GENERAL = " However, your Plan Document also states that if you are hospitalized, benefits will be payable immediately. Because you were hospitalized during your Benefit Waiting Period on ";
const string A_GENERAL = " However, your Plan Document also states that if you suffer from an accident, benefits will be payable immediately. Because you suffered from an accident during your Benefit Waiting Period on ";
const string BEGIN_ON = ", your benefits will begin on ";