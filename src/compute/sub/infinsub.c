char *infin_sub(char *fir, char *sec, char *base, char *ops)
{
    char *result;

    if (fir[0] == ops[3] && sec[0] == ops[3])
        result = infin_add(fir, sec + 1, base, ops);
    if (fir[0] == ops[3] && sec[0] != ops[3]) {
        insert_at_beg(&sec, ops[3], 1);        
        result = infin_add(fir, sec, base, ops);
    }
    if (fir[0] != ops[3] && sec[0] == ops[3])
        result = infin_add(fir, sec + 1, base, ops);
    if (fir[0] != ops[3] && sec[0] != ops[3]) {
        insert_at_beg(&sec, ops[3], 1);
        result = infin_add(fir, sec, base, ops);
    }
    return clean_str(result, base, ops);
}
