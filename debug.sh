#!/bin/bash
# debug.sh

echo "=== So_long Debug Session ==="
echo "Project directory: $(pwd)"
echo "Executable: so_long"
echo "Starting GDB..."

gdb -x <(cat << EOF
set pagination off
set print pretty on

# Break at main
break main
commands
    echo "Starting main...\n"
    continue
end

# Break at mlx_init
break mlx_init
commands
    echo "Initializing MLX...\n"
    continue
end

# Break at key handling (adjust function name if different)
break key_handler
commands
    printf "Key pressed: %d\n", keycode
    continue
end

# Run the program with map
run maps/map.ber

EOF
) ./so_long
