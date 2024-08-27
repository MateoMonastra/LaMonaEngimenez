#pragma once

#ifdef MONA_ENGIMENEZ_EXPORTS
#define MONA_ENGIMENEZ __declspec(dllexport)
#else
#define MONA_ENGIMENEZ __declspec(dllimport)
#endif