# image, kernel, padding, stride
import numpy as np
def conv2d(image, kernel, padding, stride):
    bs, hin, win = image.shape
    kh, kw = kernel.shape
    out_h = (hin + 2 * padding - kh) // stride + 1
    out_w = (win + 2 * padding - kw) // stride + 1
    out = np.zero((bs, out_h, out_w))
    for i in range(bs):
        for h in range(out_h):
            for w in range(out_w):
                for k_h in range(kh):
                    for k_w in range(kw):
                        out[i, h, w] += image[i, h * stride + k_h,
                        w * stride + k_w ]* kernel[k_h, k_w]
    return out