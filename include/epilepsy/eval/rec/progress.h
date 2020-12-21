#ifndef EPILEPSY_EVAL_REC_PROGRESS_H
#define EPILEPSY_EVAL_REC_PROGRESS_H

#define EPILEPSY_PRIV_REC_NEXT(next_lvl, choice, ...) EPILEPSY_PRIV_REC_NEXT_##choice(next_lvl)
#define EPILEPSY_PRIV_REC_NEXT_0continue(next_lvl)    EPILEPSY_PRIV_REC_##next_lvl
#define EPILEPSY_PRIV_REC_NEXT_0stop(_next_lvl)       EPILEPSY_PRIV_REC_HALT

#define EPILEPSY_PRIV_REC_HALT(...) __VA_ARGS__

#endif // EPILEPSY_EVAL_REC_PROGRESS_H