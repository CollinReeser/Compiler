git checkout master
echo "Note: Current working branch is now master"
ls -A | xargs git add
git commit -a
git push -u origin master
