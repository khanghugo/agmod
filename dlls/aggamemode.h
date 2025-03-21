//++ BulliT

#if !defined(AFX_AGGAMEMODES_H__B6D8EF5B_9423_4422_B935_1D71B6146DCA__INCLUDED_)
#define AFX_AGGAMEMODES_H__B6D8EF5B_9423_4422_B935_1D71B6146DCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "agglobal.h"
#include "aggame.h"

#include <map>

class AgGameMode
{
    typedef map<AgString, AgGame*, less<AgString> > AgGameMap;
    AgGameMap m_mapGames;
    void LoadGames();
    AgGame* pCurrent;
    float  m_fNextCheck;
    float  m_fNextFpsLimitCheck;
    float  m_fNextCvarCheck;

    static constexpr float MIN_FPS_LIMIT_CHECK_INTERVAL = 0.001;

    static constexpr float CVARS_CHECK_INTERVAL = 5.0;

public:
    AgGameMode();
    virtual ~AgGameMode();

    void Init();
    void Think();

    void ExecConfig();
    void Help(CBasePlayer* pPlayer = NULL);
    bool HandleCommand(CBasePlayer* pPlayer);

    void Gamemode(const AgString& sGamemode, CBasePlayer* pPlayer = NULL);
    bool IsGamemode(const AgString& sGamemode);
    bool IsAllowedGamemode(const AgString& sGamemode, CBasePlayer* pPlayer = NULL);

    void NextGamemode(const AgString& sGamemode, CBasePlayer* pPlayer = NULL);
};

extern DLL_GLOBAL AgGameMode GameMode;
const char* AgGamenameChar();
AgString AgGamename();
AgString AgGamedescription();
AgString AgSanitizedShortGamename();

//++ muphicks
enum enumGameType { STANDARD = 0, ARENA = 1, LMS = 2, CTF = 3, ARCADE = 4, SGBOW = 5, INSTAGIB = 6, DOM = 7 };
//-- muphicks
extern DLL_GLOBAL BYTE g_GameType;
inline BYTE AgGametype()
{
    return g_GameType;
};

#endif // !defined(AFX_AGGAMEMODES_H__B6D8EF5B_9423_4422_B935_1D71B6146DCA__INCLUDED_)
//-- Martin Webrant
