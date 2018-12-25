// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';

    if (y == 8)
    {
        return x;
    }
    else if (y == 4)
    {
        return x * 2;
    }
    else if (y == 2)
    {
        return x * 4;
    }
    else
    {
        return 0;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    if (strlen(note) == 2)
    {
        int octave = note[1] - '0';
        if (octave == 4)
        {
            int basefrequency = 440;

            switch (note[0])
            {
                case 'A':
                    return round(basefrequency * pow(2, (double) 0 / 12));
                    break;
                case 'B':
                    return round(basefrequency * pow(2, (double) 2 / 12));
                    break;
                case 'C':
                    return round(basefrequency * pow(2, (double) - 9 / 12));
                    break;
                case 'D':
                    return round(basefrequency * pow(2, (double) - 7 / 12));
                    break;
                case 'E':
                    return round(basefrequency * pow(2, (double) - 5 / 12));
                    break;
                case 'F':
                    return round(basefrequency * pow(2, (double) - 4 / 12));
                    break;
                case 'G':
                    return round(basefrequency * pow(2, (double) - 2 / 12));
                    break;
            }
        }
        else if (octave > 4)
        {
            int basefrequency = 440 * 2 * (octave - 4);

            switch (note[0])
            {
                case 'A':
                    return round(basefrequency * pow(2, (double) 0 / 12));
                    break;
                case 'B':
                    return round(basefrequency * pow(2, (double) 2 / 12));
                    break;
                case 'C':
                    return round(basefrequency * pow(2, (double) - 9 / 12));
                    break;
                case 'D':
                    return round(basefrequency * pow(2, (double) - 7 / 12));
                    break;
                case 'E':
                    return round(basefrequency * pow(2, (double) - 5 / 12));
                    break;
                case 'F':
                    return round(basefrequency * pow(2, (double) - 4 / 12));
                    break;
                case 'G':
                    return round(basefrequency * pow(2, (double) - 2 / 12));
                    break;
            }
        }
        else if (octave < 4)
        {
            int basefrequency = 440 / ((4 - octave) * 2);

            switch (note[0])
            {
                case 'A':
                    return round(basefrequency * pow(2, (double) 0 / 12));
                    break;
                case 'B':
                    return round(basefrequency * pow(2, (double) 2 / 12));
                    break;
                case 'C':
                    return round(basefrequency * pow(2, (double) - 9 / 12));
                    break;
                case 'D':
                    return round(basefrequency * pow(2, (double) - 7 / 12));
                    break;
                case 'E':
                    return round(basefrequency * pow(2, (double) - 5 / 12));
                    break;
                case 'F':
                    return round(basefrequency * pow(2, (double) - 4 / 12));
                    break;
                case 'G':
                    return round(basefrequency * pow(2, (double) - 2 / 12));
                    break;
            }
        }
    }

    else if (strlen(note) == 3)
    {
        int octave = note[2] - '0';

        if (octave == 4)
        {
            int basefrequency = 440;

            switch (note[0])
            {
                case 'A':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) 1 / 12));
                    }
                    else if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 1 / 12));
                    }
                    break;
                case 'B':
                    if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) 1 / 12));
                    }
                    break;
                case 'C':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 8 / 12));
                    }
                    break;
                case 'D':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 6 / 12));
                    }
                    else if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 8 / 12));
                    }
                    break;
                case 'E':
                    if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 6 / 12));
                    }
                    break;
                case 'F':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 3 / 12));
                    }
                    break;
                case 'G':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 1 / 12));
                    }
                    else if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 3 / 12));
                    }
                    break;
            }
        }

        else if (octave > 4)
        {
            int basefrequency = 440 * 2 * (octave - 4);

            switch (note[0])
            {
                case 'A':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) 1 / 12));
                    }
                    else if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 1 / 12));
                    }
                    break;
                case 'B':
                    if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) 1 / 12));
                    }
                    break;
                case 'C':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 8 / 12));
                    }
                    break;
                case 'D':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 6 / 12));
                    }
                    else if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 8 / 12));
                    }
                    break;
                case 'E':
                    if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 6 / 12));
                    }
                    break;
                case 'F':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 3 / 12));
                    }
                    break;
                case 'G':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 1 / 12));
                    }
                    else if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 3 / 12));
                    }
                    break;
            }
        }

        else if (octave < 4)
        {
            int basefrequency = 440 / ((4 - octave) * 2);

            switch (note[0])
            {
                case 'A':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) 1 / 12));
                    }
                    else if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 1 / 12));
                    }
                    break;
                case 'B':
                    if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) 1 / 12));
                    }
                    break;
                case 'C':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 8 / 12));
                    }
                    break;
                case 'D':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 6 / 12));
                    }
                    else if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 8 / 12));
                    }
                    break;
                case 'E':
                    if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 6 / 12));
                    }
                    break;
                case 'F':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 3 / 12));
                    }
                    break;
                case 'G':
                    if (note[1] == '#')
                    {
                        return round(basefrequency * pow(2, (double) - 1 / 12));
                    }
                    else if (note[1] == 'b')
                    {
                        return round(basefrequency * pow(2, (double) - 3 / 12));
                    }
                    break;
            }
        }
    }
    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) < 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}