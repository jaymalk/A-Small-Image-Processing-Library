import cv2
import sys

if __name__ == '__main__':
    try:
        IMG = cv2.imread(sys.argv[1], 0)

        if IMG is None:
            print("File doesn't exist please see.\n")
            sys.exit(1) # Gives instruction code 512

        if IMG.shape != [28, 28]:
            IMG_2 = cv2.resize(IMG, (28, 28))
            IMG = IMG_2.reshape(28, 28, -1)
        else:
            IMG = IMG.reshape(28, 28, -1)

        IMG = 1 - IMG/255.0 # Black font on white background

        _F = open('.temp', 'w+')
        for i in range(28):
            for j in range(28):
                _F.write(str(IMG[i][j][0])+'\n')
        _F.close()

    except:
        sys.exit(2)
