# UI Guide

`WBP_HUD` is the Widget Blueprint shown on the player's screen.

## Information and presentation

```plaintext
C++: CollectedCollectibles = 2
                |
                v
UMG:       "Items: 2 / 3"
```

C++ owns the game information. UMG decides how it looks.

`ItemsText` reads `CollectedCollectibles` and `RequiredCollectibles` from `WorkshopCharacter`. `ItemsProgressBar` calls `GetCollectibleProgress()`.

## Common widgets

| Widget | What it does |
|---|---|
| Canvas Panel | Places items freely on the screen. |
| Vertical Box | Stacks items top to bottom. |
| Horizontal Box | Places items side by side. |
| Overlay | Places items on top of each other. |
| Border | Adds a background and padding. |
| Text | Shows words or numbers. |
| Image | Shows a picture or colour. |
| Progress Bar | Shows a value from 0 to 100%. |
| Anchors | Keep UI attached to an edge or corner. |

## Main activity

1. Open `WBP_HUD`.
2. Select `ItemsText`.
3. Change its font size, alignment, and colour.
4. Move it or place it in a simple layout container.
5. Add Text saying `Collect all 3 items!`.
6. Compile, save, and press Play.

You changed how information looks without changing the game rule.

## Finished early?

Try an Image, Border, background colour, different padding, new anchors, another screen corner, or a different progress-bar colour. Test a different viewport size too.
