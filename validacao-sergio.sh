sort --random-sort webkb.svm > webkbrandom.svm
wc -l webkbrandom.svm
split -l num_linhas_cadafold webkbrandom.svm
