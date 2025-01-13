# babble
Small toy for randomly generating plausible english words.

Designed to be expandable, taking a list of objects that supply a list of weights for each letter at every step in the generation process, tallies them up, then uses them to make a weighted choice for what letter to use next. Objects each represent some implicit tendency in english vocabulary, such as the average distance between vowels and the relative frequencies of letters at different points in the word.

Very fudgy with the numbers, definitely needs tuning before it makes anything that isn't 70% unpronouncable gibberish. Mostly intended as a fun statistics/linguistics project.

## Usage
```
babble.exe [-h] [-l <word length>] [-n <number of words>]
-h						Show this help menu.
-l <word length>		Length of each generated word. Must be between 3-15 inclusive. Default is random.
-n <number of words>	Number of words to generate in one invocation. Defaults to 1.
```