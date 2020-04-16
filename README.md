### Description

This is an equivalent for windows of the tool jstest.
Unfortunately, it does not support axes 2 to 5 currently.

<b> Forked from https://github.com/yazgoo/jstest-windows </b>

### Building
#### Ubuntu
1. ```sudo apt install mingw-w64```
2. ```make clean```
3. ```make```


### Usage
1. Execute the built .exe
2. Currently, for the refresh feature (vs each poll on a new line) the text in the prompt window <b>must not</b> wrap around. No workaround for small screens as of now.

#### Changing Polled Gamepad
1. WIN+R
2. ```joy.cpl```
3. Enter or OK
4. Click ```Advanced...```
5. Change ```Preferred Device``` dropdown