#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef void(*callback_t)(double, double);

void ProcBar(double filesize, double current);
