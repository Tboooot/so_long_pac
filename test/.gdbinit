# .gdbinit
set pagination off
set print pretty on
set history save on
set history filename .gdb_history
set disassembly-flavor intel

# Common breakpoints for so_long
break main
break mlx_init
break mlx_new_window
break mlx_loop

# If you have these functions, add breakpoints for them
break key_handler
break render_map
break move_player
