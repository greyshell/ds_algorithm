# Description

Learning Data Structure and Algorithm using `C`.


## Git Workflow to maintain the repo

- Check the last commit made from which system. 
```
git show --summary
```

- If the last commit was made from a `different` system then we need to
`sync` the `local` repo with `remote`.
```
git pull --rebase
```

- Update the `local` repo and push the code into _remote_ branch.
```
git commit -am "<system_name>: message" && git push
``` 
