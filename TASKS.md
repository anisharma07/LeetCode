# Task Queue

Claude checks this file every 5 hours and works through the unchecked tasks
in order, marking each one `[x]` when it's done and pushing the progress.

Status markers: `[ ]` todo · `[~]` in progress / partially done · `[x]` done

## Tasks

<!-- Add tasks below, one per line, e.g.:
- [ ] Solve LeetCode #42 Trapping Rain Water in C++ as 42.TrappingRainWater.cpp
-->
- [ ] **Drive lecture resources** (source: https://drive.google.com/drive/folders/1ls05OiO4qAvMuijJmaUvQPFRqHDXlDu_)
  - [ ] Get every PPT/PDF in the folder, plus the syllabus
  - [ ] Check each one against the design system; convert the ones that don't match
  - [ ] Rename the PPTs lecture-wise, following the syllabus and the naming of the already-converted decks
  - [ ] Create a new resource for any syllabus lecture that has none
  - [ ] Analyze the question papers in the folder and build a master paper
  - Design system: networks_ppt_design_system — https://claude.ai/artifact/UoYjUAC59na2nj2znbokif (read it with the Artifact tool before converting anything)
  - Output: save every finished deck, and the master paper, back into the same Drive folder as PDF
  - Status (2026-11-18): Google Drive connected on the account; waiting for a session that has the Drive connector loaded

## Log

<!-- Claude appends a short note after each run: date, what got done, what's left. -->
- 2026-11-18 15:11 UTC: Drive lecture resources still blocked — this session has no Google Drive connector. Nothing done; all 5 sub-steps remain.
- 2026-11-18 16:54 UTC: Drive lecture resources still blocked. This session has no Google Drive connector either (no Drive tools, nothing listed as connected). Nothing done; all 5 sub-steps remain. Set up a scheduled task that runs every 5h to keep working through this file, but it could not store the Drive connector, so those runs won't have Drive tools yet either.
