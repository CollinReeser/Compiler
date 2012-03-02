echo -e "n\NOTE: Panicking on \"develEnvSimp\" branch."
git checkout develEnvSimp
git reset ORIG_HEAD --hard
echo "Note: Current working branch is now develEnvSimp"
