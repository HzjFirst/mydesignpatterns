#ifndef NUMSEQ_H
#define NUMSEQ_H

const int seq_num = 3;
extern int (*seq_func[seq_num])(int);

int f1(int a);
int f2(int a);
int f3(int a);

#endif // NUMSEQ_H
