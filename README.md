# Pi-Pico-Bootloader-Reset-Library
A pre-built ISR to reset the Pico to bootloader with the press of a button without requiring USB uplug/replug.

## Usage
### Button Wiring
One end of the button needs to be connected to the GPIO pin that will be used for reset. This pin will be pulled high so the other end of the button will need to be connected to ground.
### Enable
Add the library directory to the root directory of your project.

Edit _CMakeLists.txt_:
- Update `target_include_directories` to add `/library/include` path for the header file.
  
  ```python
  target_include_directories(motor_control PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/library/include
  )
  ```
- Add `library/src/bootloader.c` under `add_executable`.
  
  ```python
  add_executable(motor_control motor_control.c library/src/bootloader.c)
  ```

Call the function to enable the ISR.
```C
#define RESET_PIN 16

int main()
{
    bootloader_reset_init(RESET_PIN);
```
