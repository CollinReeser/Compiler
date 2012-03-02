git checkout develEnvSimp
echo "Note: Current working branch is now develEnvSimp"
ls -A | xargs git add
git commit -a
git push -u origin develEnvSimp
