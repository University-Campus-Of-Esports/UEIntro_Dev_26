# Behaviour Tree Guide

## The main parts

- `BP_Guard`: the character you can see.
- `BP_GuardController`: starts the Behaviour Tree.
- `BT_Guard`: lists the guard's actions.
- `BB_Guard`: stores information for the tree.
- NavMesh: shows where the guard can walk.

Press **P** in the level viewport. Green means the AI can walk there.

## The patrol

```plaintext
BT_Guard

Sequence
|
+-- Find Random Location
+-- Move To
+-- Wait
```

Each time it runs:

1. `BTT_FindRandomLocation` finds a reachable point.
2. It saves the point in `TargetLocation`.
3. `Move To` walks the guard there.
4. `Wait` pauses for two seconds.
5. The tree starts again.

`TargetLocation` is a Vector containing an X, Y, and Z position.

## Useful words

- **Task:** one action.
- **Sequence:** runs tasks in order and stops if one fails.
- **Selector:** tries choices until one works.
- **Decorator:** a condition, such as “only run if a target exists.”
- **Blackboard:** values the tree can read and change.
- **AI Controller:** controls an AI Pawn or Character.
- **NavMesh:** the walkable area.

## Main activity

1. Play and watch the guard.
2. Open `BT_Guard`.
3. Change **Wait** from `2.0` to `5.0`.
4. Play again.
5. Leave the tree open during Play and watch active nodes light up.

The guard pauses longer because the Behaviour Tree controls its timing.

## Finished early?

Try a wait of `0.5` or `10.0`, change the patrol radius, change the guard's speed, duplicate a Wait, or watch `TargetLocation` during Play.

You can also rearrange tasks or compare a Selector with a Sequence. Use Undo when finished.
