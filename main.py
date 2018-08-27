#!/usr/bin/python3
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from absl import app
from absl import flags
from absl import logging

import cv2

FLAGS = flags.FLAGS
flags.DEFINE_string('im_path', None, 'The path of the image to label')

ref_pt = []
def main(argv):
	logging.info('Loading file %s', FLAGS.im_path)
	im = cv2.imread(FLAGS.im_path)

	# Do something with the image

if __name__ == '__main__':
	app.run(main)