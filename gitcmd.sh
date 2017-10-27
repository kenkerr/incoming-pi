CMD=$1
case "$CMD" in
    init)
        echo "# incoming-pi" >> README.md
        git init
        git add README.md
        git commit -m "first commit"
        git remote add origin https://github.com/kenkerr/incoming-pi.git
        git push -u origin master
        ;;

    update)
        git pull https://github.com/kenkerr/incoming-pi.git
        ;;

    commit) 
        git add .
        git commit
        git push
        ;;

    *)
        echo "Usage: $0 {update | commit}"
        exit 1
esac
