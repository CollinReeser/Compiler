echo -e "n\NOTE: Panicking on \"master\" branch."
git checkout master
git reset ORIG_HEAD --hard
echo -e "n\NOTE: Current working branch is now master\n"
