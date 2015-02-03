#ifndef DIALOGS_H
#define DIALOGS_H

#include <iostream>

#include "teamhandler.h"
#include "teamplayer.h"
#include "teamleader.h"

void addPlayerDialog(TeamHandler& th);
void addLeaderDialog(TeamHandler& th);
void playerInfoDialog(TeamHandler& th);
void changePlayerShirtNumberDialog(TeamHandler& th);
void removeMemberDialog(TeamHandler& th);

#endif