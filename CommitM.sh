git checkout master
echo -e "n\NOTE: Current working branch is now master\n"
ls -A | xargs git add
git commit -a
git push -u origin master
