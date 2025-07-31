#include<stdio.h>

int check (
    int q,
    int n
) {
    if(
        q + n == 0x09 &&
        q - n == n
    ) {
        return ( (
                q | n 
                )
                == 0x07 && (
                q & n
                )
                == q / n
        );
    };
    return
        !0x01;
}

int main(
    int argc,
    char *argv[]
) {
    int n,
    q;
    scanf(
        "%d%d",
        &n,
        &q
    );
    if( (
            bool
        )
        check (
            n,
            q
        )
    ) {
        printf(
            "%u%c%u%c%u%c",
            0x20,
            0x0a,
            0x2e,
            0x0a,
            0x36,
            0x0a
        );
        return
            !0x01;
    }
    char a[
        0x0f
    ] = {
        0x49,
        0x27,
        0x6d,
        0x20,
        0x73,
        0x6f,
        0x20,
        0x73,
        0x6c,
        0x65,
        0x65,
        0x70,
        0x79,
        0x21,
        0x0a
    };
    for (
        int i = 0x00;
        i < 0x0f;
        i += 0x01
    ) {
        printf (
            "%c",
            *(
                i + a
            )
        );
    };
    return
        !0x01;
}
