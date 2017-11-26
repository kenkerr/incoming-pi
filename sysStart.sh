SYSTEM=$(uname -a)

if [[ $SYSTEM == *"raspberrypi"* ]]; then
    echo "Starting incoming on Pi"
    BINDIR="~/projects/incoming/bin"
    MY_EVENT_LOG=~/projects/incoming/logs/event.log
else
    echo "Starting incoming on MAC"
    BINDIR="/Users/kenkerr/projects/incoming-pi/bin"
    MY_EVENT_LOG=~/projects/incoming-pi/logs/event.log
fi

export MY_EVENT_LOG
$BINDIR/testLogger 
